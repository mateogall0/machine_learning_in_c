#!/usr/bin/env python3

import numpy as np

lib_train = np.load('../data/Binary_Train.npz')
X_train_3D, Y_train = lib_train['X'], lib_train['Y']
X_train = X_train_3D.reshape((X_train_3D.shape[0], -1)).T
lib_dev = np.load('../data/Binary_Dev.npz')
X_dev_3D, Y_dev = lib_dev['X'], lib_dev['Y']
X_dev = X_dev_3D.reshape((X_dev_3D.shape[0], -1)).T

header = f"Shape: {X_train.shape}"
np.savetxt('../one_neuron/X_train', X_train, fmt='%.16f', header=header)

header = f"Shape: {Y_train.shape}"
np.savetxt('../one_neuron/Y_train', Y_train, fmt='%.16f', header=header)

header = f"Shape: {X_dev.shape}"
np.savetxt('../one_neuron/X_dev', X_dev, fmt='%.16f', header=header)

header = f"Shape: {Y_dev.shape}"
np.savetxt('../one_neuron/Y_dev', Y_dev, fmt='%.16f', header=header)