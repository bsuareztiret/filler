# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    interface.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsuarez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 15:03:28 by bsuarez-          #+#    #+#              #
#    Updated: 2019/09/05 14:57:38 by bsuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from tkinter import *
import os
from os import listdir
from os.path import isfile, join

def create_grid_0(window, grid, Y, X):
    dp = 100
    p = 0
    canvas = Canvas(window, bg = 'white', width = 800, height = 800)
    # print(data[])
    # grid = data[2 * i]
    # print(grid)
    # for y in range(0, 426, 26):
    #     for x in range(0, 374, 26):
    #         colors = select_colors(grid[p])
    #         p = canvas.create_rectangle(dp + x, dp + y, dp + 26 + x, dp + 26 + y, outline = 'black', fill = colors)
    py = 600 // Y
    px = 595 // X
    for y in range(0, 600, py):
        for x in range(0, 595, px):
            colors = select_colors(grid[p])
            p = canvas.create_rectangle(dp + x, dp + y, dp + px + x, dp + py + y, outline = 'black', fill = colors)
    canvas.grid(row = 0, column = 0)
    canvas.after(15)

def select_colors(p):
    colors = 'white'
    if p == 'X':
        colors = 'red'
        return colors
    if p == 'x':
        colors = 'rosybrown'
        return colors
    if p == 'O':
        colors = 'blue'
        return colors
    if p == 'o':
        colors = 'royalblue'
        return colors
    else:
        colors = 'white'
    return colors

def delete():
    Canvas.delete(ALL)

def open_setgame():
    files = [f for f in listdir("./set_game") if isfile(join("./set_game", f))]
    data = []
    for name in files:
        sets = join("./set_game", name)
        file = open(sets, "r")
        lines = file.readlines()
        for line in lines:
            data.append(line.strip())
        file.close()
    return data

window = Tk()
window.title('Filler')

x = 1200
y = 1200
i = 0
data = []

area = Canvas(window, width = x, height = y, bg = 'white')
area.pack(padx = 10, pady = 10)

data = open_setgame ()
X = int (data[1])
Y = int (data[0])
while i < (len(data)):
    if i == 0:
        print(data[2])
        grid = data[2]
        i = 2
    if i > 1:
        i += 3
        if (i < len(data)):
            grid = data[i]
            print(data[i])
    create_grid_0(area, grid, Y, X)
#label_1 = Label(window, text = 'Filler', fg = 'red')
#label_1.pack()
#output = os.system("./../resources/filler_vm -f ../resources/maps/maps01 0&")
#print (os.system("./../resources/filler_vm -f ../resources/maps/maps01"))

#button_go = Button(window, text = 'go', command = grid(window))
#button_go.pack(side = LEFT, padx = 10, pady = 10)

button_delete = Button(window, text = 'delete', command = delete)
button_delete.pack(side = LEFT, padx = 5, pady = 5)

button_1 = Button(window, text = 'exit', command = window.destroy)
button_1.pack(side = LEFT, padx = 5, pady = 5)

window.mainloop()
# area.after(1500)
