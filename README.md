# CNN en C++ desde cero

Este proyecto implementa una red neuronal convolucional (CNN) simple en **C++ puro**, sin usar librerías externas de deep learning. Es una implementación educativa para entender los conceptos básicos de una CNN, incluyendo:

- Capas convolucionales
- Función de activación ReLU
- Pooling (max, min o promedio)
- Clasificador MLP (perceptrón multicapa)

## 📌 ¿Qué hace este proyecto?

La CNN toma como entrada una imagen de ejemplo (simulada con datos dummy) y la procesa a través de dos capas convolucionales, funciones de activación ReLU, pooling y una capa final MLP que produce un vector de salida (por ejemplo, para clasificación en 10 clases).

---

## 🗂 Estructura del Proyecto

```bash
.
├── main.cpp               # Punto de entrada principal
├── tensor.h/.cpp          # Clase Tensor para representar tensores 3D (datos de imágenes)
├── conv_layer.h/.cpp      # Capa convolucional con paso hacia adelante
├── relu.h/.cpp            # Capa de activación ReLU
├── pooling_layer.h/.cpp   # Capa de pooling: max, min o promedio
├── mlp.h/.cpp             # Clasificador simple tipo MLP
├── cnn.h/.cpp             # Ensambla toda la arquitectura CNN
