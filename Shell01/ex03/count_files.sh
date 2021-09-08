#!/bin/bash
find . \( -type d -o -type f \) ! -name '.?*' | grep -c ^

