#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/wsn/HKU_UAV_Project/catkin_ws/src/vision_opencv/cv_bridge"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/wsn/HKU_UAV_Project/catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/wsn/HKU_UAV_Project/catkin_ws/install/lib/python2.7/dist-packages:/home/wsn/HKU_UAV_Project/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/wsn/HKU_UAV_Project/catkin_ws/build" \
    "/usr/bin/python" \
    "/home/wsn/HKU_UAV_Project/catkin_ws/src/vision_opencv/cv_bridge/setup.py" \
    build --build-base "/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/cv_bridge" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/wsn/HKU_UAV_Project/catkin_ws/install" --install-scripts="/home/wsn/HKU_UAV_Project/catkin_ws/install/bin"
