EXECUTABLE_NAME=Exec
TEST_FOLDER="Tests"
TESTS_COUNT=4
Success=0
Fails=0

for (( i=1; i <= $TESTS_COUNT; i++ ))
do
current_test_directory_path="$TEST_FOLDER/$i"
current_output_path="$current_test_directory_path/output.txt"
current_expected_output_path="$current_test_directory_path/expected_output.txt"
current_operation_description_path="$current_test_directory_path/desc.txt"
current_test_input_file_path="$current_test_directory_path/input.txt"

./$EXECUTABLE_NAME $current_test_directory_path
#sleep 2

#cmp_result=$(cmp --silent $current_expected_output_path $current_output_path)
cmp_result=$(diff $current_expected_output_path $current_output_path)

echo "-------------------------------------------------------"
echo -e "Test: $i\n"
echo -e "**********Input:\n$(cat "$current_test_input_file_path")\n"
#echo -e "Operation: $(cat "$current_operation_description_path")\n"
echo -e "Expected output:\n$(cat "$current_expected_output_path")\n"
echo -e "Output:\n$(cat "$current_output_path")\n"
#cmp --silent $current_expected_output_path $current_output_path && echo '### SUCCESS: Files Are Identical! ###' || echo '### WARNING: Files Are Different! ###'

if [[ -z $cmp_result ]]; then
	echo "Result: OK"
	((Success++))
else
	echo "Result: FAIL"
	((Fails++))
fi

echo -e "-------------------------------------------------------\n\n"

done

echo -e "Total: $TESTS_COUNT\nSuccess: $Success\nFailed: $Fails"

sleep 60