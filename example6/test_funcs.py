import cppimport
pet = cppimport.imp("pet")

if __name__ == '__main__':
    p = pet.Pet("Molly")
    print(p)
    print(p.getName())
    p.setName("Charly")
    print(p.getName())