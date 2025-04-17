#!/bin/sh

PID_MAX=$(cat /proc/sys/kernel/pid_max)

echo "Le PID maximal est : $PID_MAX"
