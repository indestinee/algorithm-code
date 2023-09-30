generate_py=generate.py
gt=c
test=cc
data_in=cc.in
test_out=test.out
gt_out=gt.out

cnt=0
while [ 1 = 1 ]
do

    let cnt=$cnt+1
    python3 $generate_py > $data_in
    ./$gt < $data_in > $gt_out
    ./$test < $data_in > $test_out

    diff $gt_out $test_out > /dev/null
    if [ $? != 0 ]
    then
        echo 'Wrong!'
        cat $data_in
        diff $gt_out $test_out
        break
    fi

    if [ $(($cnt % 10)) = 0 ]
    then
        echo "Done $cnt test, all correct!"
    fi
done
