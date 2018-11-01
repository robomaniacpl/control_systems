#!/usr/bin/python

import matplotlib.pyplot as plt
import sys
import numpy as np
import argparse


def read_data(fname, split_format=""):
    lines = tuple(open(fname, 'r'))
    lines = [x.strip() for x in lines]

    xdata = []
    ydata = []

    legend = []

    if split_format == "":
        line = lines[0].split()
    else:
        line = lines[0].split(split_format)
    xlabel = line[0]
    ylabel = line[1]
    if len(line[1:]) >= 1:
        legend = line[1:]

    lines = lines[1:]

    for i in range(len(lines)):
            if split_format == "":
                line = lines[i].split()
            else:
                line = lines[i].split(split_format)
            xdata.append(float(line[0]))
            if len(line) > 2:
                if i == 0:
                    for j in range(1, len(line)):
                        ydata.append([])
                for j in range(1, len(line)):
                    ydata[j-1].append(float(line[j]))
            else:
                ydata.append(float(line[1]))

    output_struct = {
        'xdata' : xdata,
        'ydata' : ydata,
        'xlabel': xlabel,
        'ylabel': ylabel,
        'legend': legend
    }
    return output_struct

def plot_data(xdata, ydata, formating=[""],
              xlabel="", ylabel="", title="", label_names=[""],
              xmin = None, xmax = None, xstep = None):

    if len(label_names) > 1:
        for i in range(len(ydata)):
            label_names.append("")
        for i in range(len(ydata)):
            plt.plot(xdata, ydata[i], formating[i], label=label_names[i])

    else:
        plt.plot(xdata, ydata, formating[0], label=label_names[0])
    # plt.plot(actual_x,actual_y,'k',label = 'real')
    # plt.xlim([-10,160])
    if xmin != None and xmax != None and xstep != None:
        plt.xticks(np.arange(xmin, xmax+1, step=xstep))
    # # plt.plot(actual_x[0],actual_y[0],'ok', label="Initial position")
    if len(label_names) > 1:
        plt.legend(loc=0, numpoints=1)
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    # if save_to_file == 'T' or save_to_file == '':
    #     plt.savefig(fig_name+".png",
    #                 format = 'png'
    #                 )
    #     plt.clf()
    # else:
    plt.show()


if __name__ == "__main__":
    if len(sys.argv)>1:
        fname = sys.argv[1]
        output_struct = read_data(fname, split_format=",")
        plot_data(output_struct['xdata'], output_struct['ydata'],
                  formating=["b.","g.","r.",'k.'],
                  xlabel=output_struct['xlabel'],
#                  ylabel=output_struct['ylabel'],
                  label_names=output_struct['legend'],
                 # title="Wplyw stezenia azotu, fosforu i glonow na jakosc wod w jeziorach"
                  )
    else:
        print("Get file name as a first argument, please!")
