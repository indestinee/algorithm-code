for executable in $(find . -perm +111 -type f)
do
  cpp_file=$executable.cpp
  if [ -f $cpp_file ]
  then
    echo $executable
    rm $executable
  fi
done
