#!/bin/bash
./faquir < entrada.faq > saida.c
gcc saida.c -o programa
./programa
