# Lem_in - @21born2code
![Screenshot intra](https://github.com/do8rolyuboff/Lem_in/blob/master/other/screenshot.png)
## Что такое Lem_in?
[Lem_in](https://github.com/do8rolyuboff/Lem_in/blob/master/other/lem-in.en.pdf)

`Lem-in` - это алгоритмический проект, ориентированный на графы.
Цель проекта состоит в том, чтобы найти оптимальный маршрут муравьев для прохождения муравьиной фермы.

Проект выполнен совместно с [btrifle](https://github.com/Sahbetdin)

### Описание
`Lem-in` - принимает "муравьиную ферму" которая представляет из себя текстовый файл, который содержит следующую информацию:

• Колличество муравьев
• Комнаты ([Имя X Y] - где X и Y координаты) 
• Ссылки ([комната (A) - комната (B)])
• Начало "муравьиной фермы" (##start)
• Конец "муравьиной фермы" (##end)
• Комментарии (#comment)

![subject.map](https://github.com/do8rolyuboff/Lem_in/blob/master/other/screen_subject.map.png)

### Вывод

Вывод начинается с буквы «L». Число после буквы L - идентификационный номер муравья, за которым следует номер комнаты в которую он переместился. Каждый муравей может шаг за "ход", а в комнате не может быть двух муравьев одновременно, и каждый "ход" выводиться с новой строки.


## Как проверить Lem_in?

`git clone https://github.com/do8rolyuboff/Lem_in.git lem_in`

`cd lem_in`

`make` 

`./lem_in < map-flow-thousand`

В репозитории есть карта, на которой можно увидеть, как работает программа.
Так же в Makefile есть отдельное правило для визуализации.
Попробуйте сделать:
`make vis`

`./lem_in -v < map-flow-thousand`

У вас откроется окно браузера, в котором вы наглядно сможете увидеть движение муравьев по "ферме"
[!vis](https://github.com/do8rolyuboff/Lem_in/blob/master/other/visual.gif)

