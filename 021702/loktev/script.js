function Stack(arr = [])
{
  this.spush = function(input) 
  { 
    arr.push(input); 
  }
  this.spop = function() 
  { 
    if(arr.length == 0) return undefined;
    return arr.pop();
  } 
  this.currentstate = arr;
}

function createstack(input)
{
  if(!(input instanceof Array))
  {
    console.log("Incorrect input");
    return 0;
  }
  return new Stack(input);
}

function test(input)
{
  var testack = createstack(input);
  if(testack == 0) 
  {
    console.log("");
    return undefined;
  }
  console.log(testack.currentstate);
  console.log("Took " + testack.spop() + " from the stack");
  console.log(testack.currentstate);
  testack.spush(3);
  testack.spush("hello there");
  console.log(testack.currentstate);
  console.log("Took " + testack.spop() + " from the stack");
  console.log("Took " + testack.spop() + " from the stack");
  console.log(testack.currentstate);
  console.log("");
  return testack.currentstate;
}

function arraydeepcomp(arr1, arr2)
{
  if(arr1.length != arr2.length) return false;
  for(let i in arr1) if(arr1[i] != arr2[i]) return false;
  return true;
}

function checktestresult(input, expected)
{
  if(expected instanceof Array && arraydeepcomp(input, expected))
  { 
    return true;
  }
  if(input === expected) return true;
  return false;
}

function tests()
{
  var result;
  console.log("Test 1. Input = [1, 1, 2]\n");
  result = test([1, 1, 2]);
  console.log("Expected output: [1,1], got: [" + result + "]");
  if(checktestresult(result, [1, 1])) console.log("Test passed\n")
  else console.log("Test failed\n");
  console.log("________________________\n");

  console.log("Test 2. Input = [3, \"hello there\", 5]\n");
  result = test([3, "hello there", 5]);
  console.log("Expected output: [3,\"hello there\"], got: [" + result + "]");
  if(checktestresult(result, [3, "hello there"])) console.log("Test passed\n")
  else console.log("Test failed\n");
  console.log("________________________\n");

  console.log("Test 3. Input = [8]\n");
  result = test([8]);
  console.log("Expected output: [], got: [" + result + "]");
  if(checktestresult(result, [])) console.log("Test passed\n")
  else console.log("Test failed\n");
  console.log("________________________\n");

  console.log("Test 4. Input = []\n");
  result = test([]);
  console.log("Expected output: [], got: [" + result + "]");
  if(checktestresult(result, [])) console.log("Test passed\n")
  else console.log("Test failed\n");
  console.log("________________________\n");

  console.log("Test 5. Input = 13\n");
  result = test(13);
  console.log("Expected output: undefined, got: " + result);
  if(checktestresult(result, undefined)) console.log("Test passed\n")
  else console.log("Test failed\n");
  console.log("________________________\n");

  console.log("Test 6. Input = \"hello there\"\n");
  result = test("hello there");
  console.log("Expected output: undefined, got: " + result);
  if(checktestresult(result, undefined)) console.log("Test passed\n")
  else console.log("Test failed\n");

  console.log("________________________\n");
  console.log("Test 7. Input = \"\"\n");
  result = test("");
  console.log("Expected output: undefined, got: " + result);
  if(checktestresult(result, undefined)) console.log("Test passed\n")
  else console.log("Test failed\n");

  console.log("________________________\n");
  console.log("Test 8. Input = [21, [34, 55]]\n");
  result = test([21, [34, 55]]);
  console.log("Expected output: [21], got: [" + result + "]");
  if(checktestresult(result, [21])) console.log("Test passed\n")
  else console.log("Test failed\n");

  console.log("________________________\n");
  console.log("Test 9. Input =  Stack([89, 144])\n");
  result = test(Stack([89, 144]));
  console.log("Expected output: undefined, got: " + result);
  if(checktestresult(result, undefined)) console.log("Test passed\n")
  else console.log("Test failed\n");

  console.log("________________________\n");
  console.log("Test 10. Input = Stack()\n");
  result = test(Stack());
  console.log("Expected output: undefined, got: " + result);
  if(checktestresult(result, undefined)) console.log("Test passed\n")
  else console.log("Test failed\n");

  console.log("________________________\n");
  console.log("Test 11. Input = [[[[233]]]] \n");
  result = test([[[[233]]]]);
  console.log("Expected output: [], got: [" + result + "]");
  if(checktestresult(result, [])) console.log("Test passed\n")
  else console.log("Test failed\n");

  console.log("________________________\n");
  console.log("Test 12. Input = undefined\n");
  result = test(undefined);
  console.log("Expected output: undefined, got: " + result);
  if(checktestresult(result, undefined)) console.log("Test passed\n")
  else console.log("Test failed\n");

  console.log("________________________\n");
  console.log("Test 13. Input = Math.NaN\n");
  result = test(Math.NaN);
  console.log("Expected output: undefined, got: " + result);
  if(checktestresult(result, undefined)) console.log("Test passed\n")
  else console.log("Test failed\n");
} \n