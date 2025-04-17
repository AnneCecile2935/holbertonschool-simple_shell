#!/bin/sh

# Affiche le PPID du processus en cours
echo "Mon PPID est : $(ps -o ppid= -p $$)"
