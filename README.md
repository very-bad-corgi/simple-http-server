# Simple template http-service on Userver Framework

[Userver installation instructions](docs/userver_install.md)

## Prebuild

## 1. Configuring && Run

### 1.1 Create symbol link to Userver Framework
Переходим в корень проекта и отбиваем
```bash
ln -s /home/user/Apps/userver/userver-framework ./third_party/userver/
```

### 1.2 Сборка
```bash
mkdir build && cd build

cmake .. && \
cmake --build . -- -j$(nproc)
```

### 1.3 Запуск
Конфигурационный файл  **config_dev.yaml** можно расположить либо:
- рядом с собранным executable файлом
- определить конкретный путь до конфига через ```--config```

```bash
./http_server --config ../configs/dev/config_dev.yaml
```

### 1.4 Проверка работоспособности:

На запрос
```
curl 127.0.0.1:8083/hello
```
Получаем ответ
```Hello, unknown user!```
