#!/bin/bash
for i in {1..3}
do
    cat t$i.out
    echo ""
done
diff t1.out t2.out