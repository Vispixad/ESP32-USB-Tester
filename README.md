<h1 align="center">ESP32-Tester</h1>
ESP32-Tester - это DIY вариант ЮСБ тестеров от различных производителей, сделанный на основе ESP32-S3N16R8. Я реализовал много различных функций от простого измерения напряжения, тока, подсчета ватт (V, A, W) - до просмотра 
протоколов которые может выдать ваш блок питания, измерения сопротивления кабеля и прочего. Проект все еще находится в разработке и прошивка с каждым днем расширяется как и его возможности.

## Содержание
- [Что такое USB Tester?](#что-такое-usb-tester)
- [Компоненты](#Компоненты)
     - [Дисплей](#главное-меню)
     - [INA3221 (АЦП)](#ngr-меню)
     - [MPU-9250 (акселерометр, гироскоп, компас)](#ngr-меню)
     - [ESP32-S3N16R8](#ngr-меню)
- [Интерфейс](#Интерфейс)
     - [Главное меню](#главное-меню)
     - [NGR меню](#ngr-меню)
     - [Графики](#графики)

## Что такое USB Tester?
**USB Tester** – это устройство, которое используется для измерения различных параметров USB-портов, таких как напряжение, ток и мощность, а также для тестирования функциональности USB-устройств. Это полезный инструмент как для обычных
пользователей, так и для профессионалов в этой области. USB Tester может быть представлен в виде небольшого прибора, который подключается к USB-порту компьютера или зарядного устройства. Он оснащен дисплеем, который показывает основные
значения, поступающие через USB-порт. Более продвинутые USB Testerы также могут предоставлять информацию о протоколах зарядки (например, BC 1.2, Qualcomm Quick Charge) и многое другое. Основная функция USB Tester состоит в том,
чтобы помочь пользователям проверить работоспособность USB-портов на устройствах, а также оценить качество зарядки различных устройств, включая мобильные телефоны, планшеты, наушники и другие гаджеты. Он также может использоваться
для проверки соответствия устройств стандартам USB и для выявления проблем с электропитанием.
<h1 align="center">Компоненты</h1>

## Дисплей
В своем проекты я использовал комопненты доступные на площадке AliExpress или покупал в местных магазинах. Первое что мы сможем увидеть в тестере это дисплей, Я выбрал **IPS 2 inch (240*320)**, он имеет хорошую цветопередачу, плотность пикселей
что делает его подходящим для этого проекта.

![TFT-2 0-inch-IC-ST7789V-RGB-240x320-SPI-wymiary-](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/62fba501-9909-4379-95e9-d13d091512f1)

## INA3221 (АЦП)
Следущее что мы можем увидеть при вкоючении тестера после дисплея это основные данные, (V, A, W) для этой цели я преобрел АЦП **INA3221**. Это цифровой трехканальный датчик тока и напряжения с шиной I2C, нам будут нужны несколько каналов так как есть
2 входных (USB-A, USB Type-C) и 2 выходных (USB-A, USB Type-C). Также он удобен тем что имеет множество индикаторов для определения ошибок в работе, что вполне можно добавить в свой проект:

![ina3221_3265472](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/86a92149-87d6-4b74-b699-448245379324)

- **LED1** — индикатор наличия питания.
- **LED2** — питание находится в запрограммированном диапазоне (0 — 26 вольт)
- **LED3** — критическая проблема такой как неверная полярность или короткое замыкание (канал CRI)
- **LED4** — ошибка измерения (Канал WAR)
- **LED5** — обрыв линии питания одного из трех выводов (Канал ТС).

Подробнее можете ознакомиться на различных сайтах, а мы продолжим. 

## MPU-9250 (акселерометр, гироскоп, компас)
У тестера есть функция поворота дисплея при наклоне (аналогичное есть в вашем смартфоне), для такого используется MPU-9250 - это 9-ти осевое устройство
(3-х осевой акселерометр, 3-х осевой гироскоп, 3-х осевой компас магнитометр). Как видим есть запас в виде компаса (поэтому если 9250 у вас стоит дорого, берите MPU6500), но пока не нашел ему применение в данном
устройстве, в свою же очередь гироскоп и акселерометр используются для функции поворота дисплея.

![513VIvLM-HL](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/6e5f72e5-f634-4b9b-84ae-83aaca236cd1)

## ESP32-S3N16R8
Далее идут различные порты, кнопки, обвзяка и сама плата вычислений это ESP32-S3N16R8. Она имеет 16Мб постоянной памяти (PSRAM), 8Мб оперативной (RAM). Этого с избытком хватает для такого проекта, но не обязательно брать версию с 8Мб оперативной - вы ее не забьете.

![scale_1200](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/34f7b422-d83c-4f71-b241-abdde5182c83)

<h1 align="center">Интерфейс</h1>

## Главное меню

Перейдем к интерфейсу самого тестера, при запуске нас встречает главное меню с основными показаниями, температурой самого устройства и индикатор **stop/start**, ниже прописанные дейсвия для кнопок на этом меню:
- **Нажатие (средняя кнопка)** - stop/start показаний (для просмотра данных если требуется)
- **Нажатие (правая кнопка)** - переход на следущее меню
- **Удержание (средняя кнопка)** - количество измерений показаний в сек (идут по кругу 2 - 5 - 50 - 1000)

## NGR меню
![IMG_20240303_034412](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/352cc639-a083-4687-9af5-93149f9224d6)
Здесь имеется отображение основных данных (V, A, W) но добавляется показ данных на **DATA** контактах **(D+, D-)**, небольшая область для показа данных с определенной ячейки (позже будет разбор), показ до 3-х возможных протоколов зарядки
для общей информации, работает ли триггер **(NONE/QC2.0...)**, запись данных:
- **Вкл - ONLINE**
- **Выкл - OFFLINE** 
(шкала показывает оставщуюся память устройства, точнее области которая для этого выделена в памяти) и лимит времени. Также из мелкого интерфейса имеется стрелка для показа направления в какой порт подключено и шкала которая заполняется в зависимости от данных.
## Графики
![IMG_20240223_194406](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/fb4622d0-aa1b-4fff-b435-4bf093ec0400)
Следущее третье меню это меню графиков, их тут 4 вида:
- **График V/A** - (напряжение, ток)
- **График D+/D-** - (плюс и минус DATA контактов)
- **График CC1/CC2** - (если вход подключен к USB-A тестер пропустит этот график из-за отсутствия таких контактов)
- **Запись кривых графиков**
На каждом из них можно сделать паузу аналогично главному меню, кроме записи там немного по другому. Тестер сам подбирает диапазон чтобы было и видно нормально кривую и не выходило за границы.
