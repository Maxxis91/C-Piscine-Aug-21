#!/bin/bash
ifconfig -a | grep -F 'ether' | cut -d " " -f 2

