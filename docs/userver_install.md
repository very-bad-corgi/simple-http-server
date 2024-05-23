
[Return to main README.md](../README.md)


## 1. Build on

### 1.1 Ubuntu 22.04

1) Качаем крайнюю релизную версию:
```bash

git clone -b v2.0 https://github.com/userver-framework/userver ./userver-framework && \
cd userver-framework
```

2) Устанавливаем зависимости:
```
sudo apt install python3
sudo apt install --allow-downgrades -y $(cat ./scripts/docs/en/deps/ubuntu-22.04.md | tr '\n' ' ')
```

3) Build && Installing Framework
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