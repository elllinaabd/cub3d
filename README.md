Данный проект основан на технологии рейкастинга - это метод преобразования ограниченной формы данных (карта этажа) в трёхмерную проекцию с помощью трассировки лучей из точки обзора в объём обзора. На основе входного файла, в котором содержатся пути к текстурам, цвета пола и потолка, а также сама двумерная карта этажа, необходимо создать игровой движок - аналог Wolfenstein 3D engine by ID Software.

Основная идея заключается в следующем: для каждой вертикальной полосы экрана (координаты x) отправляется луч, который начинается в точке местоположения игрока и имеет направление, которое соответствует направлению взгляда игрока. Затем этот луч начинает двигаться вперед по 2D-карте, пока не столкнется с квадратом карты, который является стеной. После этого, рассчитывается расстояние от этой точки попадания до игрока. На основе этого расстояния определяется насколько высоко эта стена должна быть отрисована на экране: чем дальше стена, тем она меньше и наоборот.
