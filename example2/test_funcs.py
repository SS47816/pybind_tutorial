import cppimport
funcs = cppimport.imp("wrap")

def test_add():
  assert(funcs.add(3, 4) == 7)
  print("Success")
  
if __name__ == '__main__':
  test_add()