
ARG ROS_DISTRO=humble
FROM ros:${ROS_DISTRO}-ros-core

# Use bash for all RUN commands
SHELL ["/bin/bash", "-c"]

# ---------------------------
# Install dependencies
# ---------------------------
RUN apt-get update && \
    apt-get install -y \
        python3-pip  \
        libboost-all-dev \
        ros-$ROS_DISTRO-diagnostic-updater \
        ros-$ROS_DISTRO-geometry-msgs \
        ros-$ROS_DISTRO-std-msgs \
        ros-$ROS_DISTRO-tf2 \
        ros-$ROS_DISTRO-tf2-ros \
        ros-${ROS_DISTRO}-rmw-cyclonedds-cpp \
        build-essential \
        git \
        python3-colcon-common-extensions && \
    pip install empy==3.3.4 && \
    # Clean up
    apt-get autoremove -y && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# ---------------------------
# Create workspace
# ---------------------------
WORKDIR /workspace
RUN mkdir -p src

# ---------------------------
# Copy your package
# ---------------------------
COPY ros2/src/netft_rdt_driver src/


# ---------------------------
# Build workspace
# ---------------------------
RUN source /opt/ros/$ROS_DISTRO/setup.bash && \
    colcon build --symlink-install

# ---------------------------
# Source ROS 2 and workspace
# ---------------------------
SHELL ["/bin/bash", "-c"]
RUN echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc && \
    echo "source /workspace/install/setup.bash" >> ~/.bashrc
ENV ROS_DOMAIN_ID=10

# ---------------------------
# Default entrypoint
# ---------------------------
ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/$ROS_DISTRO/setup.bash && source /workspace/install/setup.bash && exec \"$@\"", "--"]

# ---------------------------
# Default command
# ---------------------------
CMD ["ros2", "launch", "netft_rdt_driver", "ft_bringup.launch.py"]
