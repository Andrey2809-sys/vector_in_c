# 🚀 C Vector (Dynamic Array)

Simple dynamic array implementation (like C++'s `std::vector`) in pure C.  
**Perfect for embedding in your projects!**

## 📦 Key Features
- ✅ Auto-expands when adding elements  
- ✅ Bounds checking (`at()`)  
- ✅ Easy integration (just 1 header)  
- ✅ Pure C (no dependencies)  

## 🛠 Build
```bash
make       # Compile
make run   # Run example
make clean # Remove binary

/  
├── src/           # Source files  
│   └── main.c     # Usage example  
├── include/       # Headers  
│   ├── vector.h   # Interface  
│   └── vector.c   # Implementation  
└── build/         # Binaries (auto-created)

#include "vector.h" 
#include <stdio.h>

int main() {
    Vector vec;
    vector_init(&vec);
    
    vector_push(&vec, 10);
    printf("Size: %zu\n", vec.size); // Size: 1
    
    vector_free(&vec);
    return 0;
}
