mkdir dependencies
cd dependencies
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install cpr nlohmann-json magic-enum