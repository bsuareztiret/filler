# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    interface.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsuarez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 15:03:28 by bsuarez-          #+#    #+#              #
#    Updated: 2019/07/16 16:07:00 by bsuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from tkinter import *
import os

def create_grid_0(window, posx, posy, p):
    dp = 210
    colors = 'white'
    if p == 'X': p = 'red'
    else: p = 'blue'
    canvas = Canvas(window, bg = 'white', width = 800, height = 800)
    for y in range(0, 426, 26):
        for x in range(0, 374, 26):
            canvas.create_rectangle(dp + x, dp + y, dp + 26 + x, dp + 26 + y, outline = 'black', fill = colors)
            if y == posy and x == posx:
                colors = p
            else:
                colors = 'white'
#    fill_grid_O(canvas, posx, posy)

    canvas.grid(row = 0, column = 0)

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
grid = '...............\n...............\n..X............\n...............\n...............\n...............\n..............\n...............\n...............\n...............\n...............\n...............\n...............\n...............\n...............\n..........O....\n...............\n...............\n'
area = Canvas(window, width = x, height = y, bg = 'white')
area.pack(padx = 10, pady = 10)

create_grid_0(area, posx, posy, p)

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
