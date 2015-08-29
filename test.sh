#!/bin/sh
set -e

if [ $# -eq 0 ]
then
  echo "usage: $0 <size>.."
  echo "example: $0 4K 16M 64M"
  exit 0
fi

t() {
  echo -n "$1: "
  time -f '%e %M' ./$1 < in.$2 2>&1 > out.$2
  diff in.$2 out.$2
  rm out.$2
}

make -s

for s in $@
do
  echo "Size $s:"
  head -c$s /dev/zero > in.$s
  {
    t stdio $s
    t unistd $s
  } | column -t
  rm in.$s
done

make -s clean
