#!/bin/bash
git status --ignored --porcelain=v2 | sed -n '/^!\ /s/!\ //p'
