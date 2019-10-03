#!/bin/bash


function bash_expatntion_with_regexp() {
  test_str1="2226/patch-A-65646012/android-7.1.2_r5/platform/frameworks/base"
  test_str2="2223/patch-A-63666573/android-6.0.1_r20/platform/frameworks/av"

  regexp_aosp1='android-[0-9]\.[0-9]\.[0-9]_r[0-9]{1,2}'
  regexp_aosp2='android-[0-9]\.[0-9]\.[0-9]_r[0-9]{2}'

  if [[ $test_str1 =~ $regexp_aosp1 ]]; then
    echo "${BASH_REMATCH[0]}"
    aosp_ver="${BASH_REMATCH[0]}"           # eg) android-7.1.2_r5
  else
    echo "not matched"
  fi

  if [[ $test_str1 =~ $regexp_aosp2 ]]; then
    echo "${BASH_REMATCH[0]}"
    aosp_ver="${BASH_REMATCH[0]}"           # eg) Not matched
  else
    echo "NOT matched"
  fi

  if [[ $test_str2 =~ $regexp_aosp1 ]]; then
    echo "${BASH_REMATCH[0]}"
    aosp_ver="${BASH_REMATCH[0]}"           # eg) android-6.0.1_r20
  else
    echo "not matched"
  fi

  if [[ $test_str2 =~ $regexp_aosp2 ]]; then
    echo "${BASH_REMATCH[0]}"
    aosp_ver="${BASH_REMATCH[0]}"           # eg) android-6.0.1_r20
  else
    echo "not matched"
  fi
}
bash_expatntion_with_regexp


#
# Count number of words in a string
# $1 = a_string_of_multiple_words
#
function count_number_of_words_in_a_string() {
  if [ "" = "$1" ];then
    items="apple banana cherry"
  else
    items="$1"
  fi

  echo $items

  #### way#1 Count number of words in a string
  words=($items)
  echo ${#words[@]}

  #### Way#2 Count number of words in a string
  echo "$items" | wc -w

  #for item in $items; do
  #    echo "${item}"
  #done
}
count_number_of_words_in_a_string
count_number_of_words_in_a_string "animal bear cat dog"


