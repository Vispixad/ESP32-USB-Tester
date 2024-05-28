<h1 align="center">ESP32-Tester</h1>

![usb-tester](https://img.shields.io/badge/usb-tester-red?style=flat&logo=educative)
![programming](https://img.shields.io/badge/programming-blue?style=flat&logo=cplusplus)
![ESP32](https://img.shields.io/badge/ESP32-gray?style=flat&logo=espressif)

![IMG_20240528_201432](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/5fde4f38-2ab2-40d2-ab2c-9211365a272d)

> [!CAUTION]
> Если у вас возникают ошибки или другие трудности, советуем следить за
> обновлениями, а также писать об этом нам, так как проект находится в активной разработке.
> Если вы тяжело понимаете русский язык, выберите версию с более удобным вам языком: [**English**](https://github.com/Vispixad/ESP32-USB-Tester/blob/main/README_EN.md) -> **Русский** -> Українська
 
ESP32-Tester - это DIY вариант USB тестеров от различных производителей, сделанный на основе ESP32-S3N16R8. Я реализовал много разных функций от простого измерения напряжения, тока, подсчета ватт (V, A, W) - до просмотра 
протоколов которые может выдать ваш блок питания, измерения сопротивления кабеля и прочего. Проект все еще находится в разработке и прошивка с каждым днем расширяется как и его возможности.

## Содержание
- [**Что такое USB Tester?**](#что-такое-usb-tester)
- [**Компоненты**](#Компоненты)
     - [Дисплей](#дисплей)
     - [INA3221 (АЦП)](#ina3221-ацп)
     - [MPU-9250 (акселерометр, гироскоп, компас)](#mpu-9250-акселерометр-гироскоп-компас)
     - [ESP32-S3N16R8](#esp32-s3n16r8)
- [**Интерфейс**](#Интерфейс)
     - [Главное меню](#главное-меню)
     - [NGR меню](#ngr-меню)
     - [Графики](#графики)
     - [Application](#application)
- [**Fast Charge**](#fast-charge)
     - [Warning](#warning)

## Что такое USB Tester?
**USB Tester** – это устройство, которое используется для измерения различных параметров USB-портов или USB-кабелей, таких как напряжение, ток и мощность, а также для тестирования функциональности USB-устройств.

Это полезный инструмент как для обычных пользователей, так и для профессионалов в этой области. USB Tester может быть представлен в виде небольшого прибора, который подключается к USB-порту компьютера или зарядного устройства или оснащаться дисплеем, который показывает основные значения, поступающие через USB-порт. Более продвинутые USB Testerы также могут предоставлять информацию о протоколах зарядки (например, Apple, Qualcomm Quick Charge, Samsung AFC) и многое другое.

Его основная функция состоит в том, чтобы помочь пользователям проверить работоспособность USB-портов на устройствах, а также оценить качество зарядки различных устройств, включая мобильные телефоны, планшеты, наушники и другие гаджеты. Он также может использоваться для проверки соответствия устройств стандартам USB.
<h1 align="center">Компоненты</h1>

## Дисплей
В своем проекты я использовал комопненты доступные на площадке AliExpress также покупал в местных магазинах. Первое что мы сможем увидеть в тестере это сам дисплей, я выбрал **IPS 2 inch (240*320)**, он имеет хорошую цветопередачу, плотность пикселей и технологию IPS, что дает хорошие углы обзора по сравнению с TFT, таким образом он отлично подходит для этого проекта.

![TFT-2 0-inch-IC-ST7789V-RGB-240x320-SPI-wymiary-](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/62fba501-9909-4379-95e9-d13d091512f1)

## INA3221 (АЦП)
Следущее что мы можем увидеть после включения устройства это основные данные: V, A, W, для этой цели я преобрел АЦП **INA3221**. Это цифровой трехканальный датчик тока и напряжения с шиной I2C, нам будут нужны несколько каналов так как имеются 2 входных (USB-A, USB Type-C) и 2 выходных (USB-A, USB Type-C). Также он удобен тем что имеет множество индикаторов для определения ошибок в работе, что вполне можно добавить в свой проект:

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
Далее идут различные порты, кнопки, обвязка и сама плата МК - это ESP32-S3N16R8. Она имеет 16Мб постоянной памяти (PSRAM), 8Мб оперативной (RAM). Этого с избытком хватает для такого проекта, но не обязательно брать версию с 8Мб RAM - вы ее не сможете полностью забить.

![scale_1200](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/34f7b422-d83c-4f71-b241-abdde5182c83)

<h1 align="center">Интерфейс</h1>

## Главное меню
![IMG_20240528_162028](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/4a0813a4-f7ec-45e7-909a-f29be2995bdc)
Перейдем к интерфейсу самого тестера, при запуске нас встречает главное меню с основными показаниями, температурой самого устройства (данные берутся с встроенного температурного датчика ESP32) и индикатор **stop/start**, ниже прописаны дейсвия для кнопок на этом меню:
- **Нажатие (средняя кнопка)** - stop/start показаний (для просмотра данных если требуется)
- **Нажатие (правая кнопка)** - переход на следущее меню
- **Удержание (средняя кнопка)** - количество измерений показаний в сек (идут по кругу 5 - 50 - 1000)

## NGR меню
![IMG_20240528_171536](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/7a422ec2-4542-4a1c-abb6-830a2bd5b0a4)
Здесь имеется отображение основных данных (V, A, W) но уже добавляется показ данных на **DATA** контактах **(D+, D-)**, небольшая область для показа данных с определенной ячейки (позже будет разбор), показ до 3-х возможных протоколов зарядки
для общей информации, работает ли триггер **(NONE/QC2.0...)**, запись данных:
- **Вкл - ONLINE**
- **Выкл - OFFLINE** 
(шкала показывает оставщуюся память устройства, точнее области которая для этого выделена в памяти) и лимит времени. Также из мелкого интерфейса имеется стрелка для показа направления в какой порт подключено и шкала которая заполняется в зависимости от данных.
## Графики
![IMG_20240304_130422](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/a5f01732-1c56-4ccc-8536-27ed29358283)
Следущее третье меню это меню графиков, их тут 3 вида:
- **График V/A** - (напряжение, ток)
- **График D+/D-** - (плюс и минус DATA контактов)
- **График CC1/CC2** - (CC1 и CC2).
На каждом из них можно сделать паузу аналогично главному меню. Тестер сам подбирает диапазон отображения чтобы было видно кривую и не выходило за границы.

> [!IMPORTANT]
> Стоит также отметить что в графике **CC1/CC2**, если у вас не подключено устройство по **USB-C** или вход подключен к USB-A тестер вам об этом сообщит и пропустит этот график из-за отсутствия таких контактов, пример показан ниже:
> 
> ![IMG_20240528_172332](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/4465e063-705b-473b-a3e9-96949952094e)

## Application
![IMG_20240528_185722](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/2edf4742-6736-4471-9b1c-fd436cc80ed9)
Последнее дочерное меню это - меню приложений или **Application**, здесь в прямоугольниках идут разветвления на другие подменю о которых написано ниже.

Также внизу показывается **время работы устройства**, что может быть полезным в некоторых случаях. По поводу управления:
- **нажатие (кнопка вперед)** мы будем выбирать разные подкатегории (выбранная отмечается синим).
- **нажатие (кнопка назад)** мы перейдем на предыдущее меню.
- **нажатие (средняя кнопка)** сделает переход в подменю или подкатегорию.

<h1 align="center">Fast Charge</h1>

## Warning
![IMG_20240528_185651](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/b84a39c4-2723-43bd-a3df-f53ae74e62f6)

При заходе в подкатегорию **Fast Charge** нас встречает предупреждение, ниже 3 пункта на выбор:
- **READY** - переход в триггеры быстрой зарядки (Samsung AfS, QC2.0, 3.0 и прочее).
- **AUTO** - переход в сканирование вашего блока питания на наличие того или инного протокола зарядки.
- **CANCEL** - выход из подкатегории.

## Detection v1.4
![IMG_20240528_221609](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/61513ae1-aaef-4ae7-a267-e4cec1c8b75c)
Разберем случай нажатия на пукт **AUTO**, вверху написана версия детектирования, статус - **Testig или Finish**, далее ниже по очереди тестрируется каждый протокол на наличие его в БП, методом вызова (триггер).

> [!NOTE]
> Подробнее о протоколах и их работе с Arduino совместимыми платами можно по ссылкам ниже:
> 
> [Что такое быстрая зарядка](https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%BE%D1%82%D0%BE%D0%BA%D0%BE%D0%BB%D1%8B_%D0%B1%D1%8B%D1%81%D1%82%D1%80%D0%BE%D0%B9_%D0%B7%D0%B0%D1%80%D1%8F%D0%B4%D0%BA%D0%B8) -> [Интеграция QC2.0 в Arduino](https://github.com/GyverLibs/QuickCharge)

## Fast Charge (Trigger)


