#!/bin/bash
cat /etc/passwd | grep -v "#"  | cut -d ":" -f 1 | sed '1!n;d' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | xargs echo | sed 's/ /, /g' | tr "[\n]" "."

