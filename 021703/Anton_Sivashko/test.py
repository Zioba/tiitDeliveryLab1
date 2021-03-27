import lib


print("\nTest 1")                                                               # Sort.
arr1 = [12, 47, 9, 2, 56, 19, 5, 32, 14]
print("Input data:", arr1)
print("Expected result: [2, 5, 9, 12, 14, 19, 32, 47, 56]")
lib.sorting(arr1)
print("Result:", arr1)
print("Test completed.")


print("\nTest 2")                                                             # Adding element.
arr1 = [12, 47, 9, 2, 56, 19, 5, 32, 14]
lib.sorting(arr1)
print("Input data:", arr1, "and 63.")
print("Expected result: [2, 5, 9, 12, 14, 19, 32, 47, 56, 63]")
lib.AddElement(63, arr1)
print("Result:", arr1)
print("Test completed.")


print("\nTest 3")                                                             # Search element
arr1 = [12, 47, 9, 2, 56, 19, 5, 32, 14]
lib.sorting(arr1)
print("Input data:", arr1, "and 19.")
print("Expected result:", 5)
print("Result:", lib.SearchElement(19, arr1))
print("Test completed.")


print("\nTest 4")                                                             # Union
arr1 = [12, 47, 9, 2, 56, 19, 5, 32, 14]
arr2 = [44, 68, 5, 32, 24, 12, 832, 69, 56, 13]
lib.sorting(arr1)
lib.sorting(arr2)
print("Input data:", arr1, "and", arr2)
print("Expected result: [2, 5, 9, 12, 13, 14, 19, 24, 32, 44, 47, 56, 68, 69, 832]")
print("Result:", lib.Union(arr1, arr2))
print("Test completed.")


print("\nTest 5")                                                               # Intersection
arr1 = [12, 47, 9, 2, 56, 19, 5, 32, 14]
arr2 = [44, 68, 5, 32, 24, 12, 832, 69, 56, 13]
lib.sorting(arr1)
lib.sorting(arr2)
print("Input data:", arr1, "and", arr2)
print("Expected result: [5, 12, 32, 56]")
print("Result:", lib.Intersection(arr1, arr2))
print("Test completed.")