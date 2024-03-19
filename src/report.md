## TASK 1 
Взять официальный докер образ с nginx и выкачать zего при помощи docker pull

![docker pull](./images/Task1.1.png)

Проверить наличие докер образа через docker images

![docker images](./images/Task1.2.png)

Запустить докер образ через docker run -d [image_id|repository]

![docker run](./images/Task1.3.png)

Проверить, что образ запустился через docker ps

![docker ps](./images/Task1.4.png)

Посмотреть информацию о контейнере через docker inspect [container_id|container_name] \
По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера

![docker inspect command](./images/Task1.8.png)

![docker inspect port](./images/Task1.6.png)

![docker inspect ip](./images/Task1.7.png)

![docker inspect size](./images/Task1.5.png)

Остановить докер образ через docker stop [container_id|container_name]

![docker stop](./images/Task1.9.png)

Проверить, что образ остановился через docker ps

![docker ps](./images/Task1.10.png)

Запустить докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду run

![docker inspect ip](./images/Task1.11.png)

Проверить, что в браузере по адресу localhost:80 доступна стартовая страница nginx

![docker inspect ip](./images/Task1.12.png)

Перезапустить докер контейнер через docker restart [container_id|container_name]

![docker inspect ip](./images/Task1.13.png)

Проверить любым способом, что контейнер запустился

![docker inspect ip](./images/Task1.14.png)

## TASK 2

Прочитать конфигурационный файл nginx.conf внутри докер контейнера через команду exec

![docker exec cat](./images/Task2.1.png)

Создать на локальной машине файл nginx.conf

![docker exec cat > nginx.conf](./images/Task2.2.png)

Настроить в нем по пути /status отдачу страницы статуса сервера nginx

![nginx.conf add server](./images/Task2.3.png)

Скопировать созданный файл nginx.conf внутрь докер образа через команду docker cp

![docker cp](./images/Task2.4.png)

Перезапустить nginx внутри докер образа через команду exec

![nginx reload](./images/Task2.5.png)

Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx

![localhost/status](./images/Task2.6.png)

![localhost/status](./images/Task2.7.png)

Экспортировать контейнер в файл container.tar через команду export \
Остановить контейнер

![docker export and stop](./images/Task2.8.png)

Удалить образ через docker rmi [image_id|repository], не удаляя перед этим контейнеры

![docker rmi](./images/Task2.9.png)

Удалить остановленный контейнер

![docker rm](./images/Task2.10.png)

Импортировать контейнер обратно через команду import

- сначала необходимо найти дополнительные аргументы командной строки при запуске nginx в контейнере, так как export их не сохраняет

![docker inspect](./images/Task2.12.png)

- теперь можно импортировать архивированный image, добавив параметры запуска 

![docker import](./images/Task2.13.png)

Запустить импортированный контейнер

![docker run](./images/Task2.14.png)

Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx

![localhost/status](./images/Task2.15.png)

## TASK 3

Сначала напишем мини сервер на C с использованием FastCgi

![server.c](./images/Task3.1.1.png)

Далее запустим докер образ на 81 порту

![docker run -d nginx](./images/Task3.2.png)

Затем скопируем файл с исходным кодом сервера в docker образ nxinx

![docker cp server.c <name_of_ran_image>](./images/Task3.3.1.png)

Настроим конфиг для nginx на слушание 81 порта и проксирование всех запросов на 127.0.0.1:8080

![nginx.conf](./images/Task3.4.1.png)

Сопируем файл с конфигурацией сервера в docker образ nxinx

![docker cp nginx.conf <name_of_ran_image>](./images/Task3.5.png)

Переходим в запущенный образ

![docker exec -it](./images/Task3.6.png)

Установим все необходимые библиотеки

![update](./images/Task3.7.png)

![gcc](./images/Task3.8.png)

![spawn-fcgi](./images/Task3.9.png)

![libfcgi-dev](./images/Task3.10.png)

Сборка исполняемого файла мини сервера

![gcc -o](./images/Task3.11.png)

Запуск сервера на порту 8080 через spawn-fcgi

![gcc -o](./images/Task3.12.png)

Проверка, что на локалхосте на порту 81 открывается наш мини сервер

![gcc -o](./images/Task3.13.png)

## Task 4

Создание докерфайла для получения своего докеробраза 

![dockerfile](./images/Task4.1.png)

Для сборке сервера в запущенном контейнере, необходимо написать скрипт для сборки и запуска самого сервера 

![run.sh](./images/Task4.2.png)

После создания файлов создаем свой образ через команду docker build

![docker build](./images/Task4.3.png)

Првоеряем, что образ создался успешно 

![docker build](./images/Task4.4.png)

После запускаем контейнер. При запуске необходимо мапить порты 80 и 81 соответсвтенно и мапить файлы конфигов инджинкса для последующего их изменения.

![docker run](./images/Task4.5.png)

Проверяем, что по локалхосту нам отдается нужная страница

![localhost:80](./images/Task4.6.png)

Теперь по заданию изменяем файл с конфигурацией сервера и добавляем проксирование 

![nginx.conf](./images/Task4.7.png)

После внесения изменений перезапускаем образ

![docker restart](./images/Task4.8.png)

И проверяем, что по адресу localhost/status отдается нужная страница 

![localhost/status](./images/Task4.9.png)

## Task 5

Для установки dockle нужно сделать утсановочный sh файл и запустить его

![sh file](./images/Task5.1.png)
![install](./images/Task5.2.png)

Проверка образа программой dockle

![install](./images/Task5.3.png)

Необходимые правки в dockerfile

![install](./images/Task5.4.png)

Билд образа 

![install](./images/Task5.5.png)

Ошибок больше нет 

![install](./images/Task5.6.png)

## Task 6

Для того, чтобы поднять необходимые докер контейнеры так, чтобы они могли общаться между собой, необходимо изменить докерфайл и run.sh из прошлых заданий (так как необходимо, чтобы после запуска контейнера он продолжал работать, а не завершался, а также чтобы у пользователя nginx был доступ необходимым каталогам).

![run.sh](./images/Task6.1.png)
![dockerfile](./images/Task6.5.png)

Также необходимо сделать еще один контейнер, который будет проксировать запросы

![dockerfile](./images/Task6.2.png)
![nginx.conf](./images/Task6.3.png)
![run.sh](./images/Task6.4.png)

Теперь необходимо написать compose.yaml

![compose.yaml](./images/Task6.6.png)

После завершения подготовки делаем сборку docker compose build

![docker compose build](./images/Task6.7.png)

И поднимаем готоврые образы 

![docker compose up](./images/Task6.8.png)

Теперь проверяем доступ к серверу 

![curl localhost](./images/Task6.9.png)