# avs-hw2
Семинарское ДЗ №2 по АВС

Компилируем и запускаем программу на каком-нибудь тестовом наборе.
![1](https://user-images.githubusercontent.com/34311075/190911930-2ca141cb-3d05-41aa-8061-f01724c12a36.png)

Что-то странное: появился какой-то ноль.

Пробуем запустить на предложенном наборе из презентации.
![2](https://user-images.githubusercontent.com/34311075/190911952-e2e7e0ef-c307-4107-88c9-a25b9fd2ca66.png)

Всё ок.

Компилируем в отладочном режиме, ставим брейкпоинт на строчке, где цикл достает из массива очередное значение. Попытаемся понять, откуда там взялся ноль. Также делаем `display i` и `display a[i]`, чтобы на каждой итерации следить за этими значениями.
![3](https://user-images.githubusercontent.com/34311075/190911989-76019267-1a81-4544-8e6e-4f8f8e4010b4.png)

Пока что все хорошо, делаем `next` до тех пор, пока не увидим что-то странное.

![4](https://user-images.githubusercontent.com/34311075/190912134-69d3aa09-d1fe-4d55-a197-cc4def80cef3.png)

Тут обнаруживаем, что, во-первых, `i = 3`, хотя индекс не должен превышать 2 - у нас же всего три числа. Ну и поскольку мы вылезли за границы, получили закономерный ноль.

Смотрим в функцию `main` и понимаем, что функция `shell_sort` вызывается с размером массива, большим на единицу, чем на самом деле. Чтобы избежать таких ошибок, в начале функции `main` запишем в переменную `size` размер массива и будем использовать эту переменную там, где нужно. Исправления можно посмотреть в [этом](https://github.com/makeitokay/avs-hw2/commit/072b1251324e0a86e1c833aca629c84a9e90edc3) коммите.

Исправили ошибку, запускаем на нашем наборе, который выдавал некорректный результат; за одно запустим на наборе из презентации, чтобы убедиться, что ничего не сломалось.
![5](https://user-images.githubusercontent.com/34311075/190912270-2c07d005-ae73-4d68-9ea1-7dd617be4640.png)

Всё работает хорошо.
