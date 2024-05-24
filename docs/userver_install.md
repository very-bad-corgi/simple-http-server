
[Return to main README.md](../README.md)

## Содержание  
- [Содержание](#содержание)
- [1. Build \&\& Installing](#1-build--installing)
  - [1.1 Ubuntu 22.04 amd64](#11-ubuntu-2204-amd64)
  - [1.2 Fedora 37 amd64](#12-fedora-37-amd64)

## 1. Build && Installing

### 1.1 Ubuntu 22.04 amd64
Перейти к [Содержание](#содержание)

1) Качаем крайнюю релизную версию:
```bash

git clone -b v2.0 https://github.com/userver-framework/userver && \
cd userver
```

2) Устанавливаем зависимости:
```
sudo apt install python3
sudo apt install --allow-downgrades -y $(cat ./scripts/docs/en/deps/ubuntu-22.04.md | tr '\n' ' ')
```

3) Configuring && Build && Installing Framework
```
cmake -S./ -B./build_debug \
    -DUSERVER_FEATURE_ROCKS=OFF \
    -DUSERVER_FEATURE_POSTGRESQL=ON \
    -DCMAKE_BUILD_TYPE=Debug \
    -DUSERVER_INSTALL=ON \
    -DUSERVER_SANITIZE="ub addr" \
    -GNinja && \
cmake --build build_debug/ -- -j$(nproc) && \
sudo cmake --install build_debug/
```

### 1.2 Fedora 37 amd64
Перейти к [Содержание](#содержание)

1) Качаем крайнюю релизную версию
```
git clone -b v2.0 https://github.com/userver-framework/userver ./userver-framework && \
cd userver-framework
```

1) Устанавливаем зависимости
```
sudo dnf install -y $(cat ./scripts/docs/en/deps/fedora-36.md | tr '\n' ' ')
```
В случае ошибки требуется убрать конфликтующий пакет, в моем случае это был ```postgresql-server```, которого в следующей команде нет - она аналогична скрипту **fedora-36.md**
``` bash
sudo dnf install -y clang-devel fmt-devel cryptopp-devel boost-devel c-ares-devel ccache cctz-devel cmake protobuf-devel python3-protobuf protobuf protobuf-compiler curl-devel g++ google-benchmark-devel grpc-devel grpc-plugins gtest-devel hiredis-devel jemalloc-devel libasan libatomic libpq-devel libubsan yaml-cpp mongo-c-driver-devel nghttp2-devel ninja openldap-devel python3-devel python3-jinja2 python3-protobuf python3-voluptuous redis yaml-cpp-devel zlib-devel libsigsegv-devel libev-devel http-parser-devel libnghttp2-devel
```

Рекомендую поставить так же:
```
sudo dnf install gcc gcc-c++ clang-devel libasan libasan-static

sudo dnf install python3-pip
pip3 install virtualenv
```

Мне так и не удалось установить их для DUSERVER_FEATURE_POSTGRESQL.. Конфликтуют друг с другом, но для поддержки фрэймворком нужны оба
```
sudo dnf install -y postgresql-server-devel postgresql-static
sudo dnf install -y postgresql-devel
```

3) Configuring && Build && Installing Framework
```
cmake -S./ -B./build_debug \
    -DSERVER_FEATURE_CRYPTOPP_BLAKE=OFF \
    -DUSERVER_FEATURE_STACKTRACE=OFF \
    -DUSERVER_FEATURE_PATCH_LIBPQ=OFF \
    -DUSERVER_FEATURE_ROCKS=OFF \
    -DUSERVER_FEATURE_POSTGRESQL=OFF \
    -DCMAKE_BUILD_TYPE=Debug \
    -DUSERVER_INSTALL=ON \
    -DUSERVER_SANITIZE="ub addr" \
    -GNinja && \
cmake --build build_debug/ -- -j$(nproc) && \
sudo cmake --install build_debug/
```