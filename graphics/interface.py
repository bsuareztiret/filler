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

def create_grid_0(window, posx, posy, grid):
    dp = 210
    i = 0
    canvas = Canvas(window, bg = 'white', width = 800, height = 800)
    for y in range(0, 426, 26):
        for x in range(0, 374, 26):
            colors = select_colors(grid[i])
            i = canvas.create_rectangle(dp + x, dp + y, dp + 26 + x, dp + 26 + y, outline = 'black', fill = colors)
    canvas.grid(row = 0, column = 0)

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

def fill_grid_O(canvas, posx, posy):
    pstart = (23 * posx) + 210
    pend = (26 * posy) + 210
    print ('pstart', pstart, 'pend', pend)
    canvas.create_rectangle(pstart, pstart, pend, pend, fill = 'black')

def delete():
    Canvas.delete(ALL)

window = Tk()
window.title('Filler')

x = 800
y = 800
posx = 1 * 26
posy = 8 * 26
p = 'O'
grid = '...................................xxx...........xxxxxx.......xxxXX......................................................................................................oo......oo......ooooooooo............OOOO................................................'
#grid = '...............\n...............\n..X............\n..xxxxx...........\n...............\n...............\n..............\n...............\n...............\n...............\n...............\n...............\n...............\n...............\n.........oooo...\n..........Ooo..\n'
area = Canvas(window, width = x, height = y, bg = 'white')
area.pack(padx = 10, pady = 10)

create_grid_0(area, posx, posy, grid)

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
