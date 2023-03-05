mkdir -p ../build
cd ../build
echo "$0: Changed to build directory"
rm -rf *
echo "$0: Removed all files from directory"
set -x
cmake -DCPP_VERSION_TEST_CXX_STANDARD="20" -GNinja ../source
set +x
echo "$0: Running CMake with Ninja as build tool"
touch debug.log
ninja > debug.log
echo "$0: Running build, saving log to /build/debug.log"
cd ../binary
echo "$0: Changed to binary directory"
./Calculator
echo "$0: Running program"
cd ../scripts
echo "$0: Changed back to scripts folder"
