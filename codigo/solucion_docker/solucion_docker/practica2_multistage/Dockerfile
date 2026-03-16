# Stage 1: Build

# partimos de una imagen ya hecha
FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04 AS builder

# Establecer la carpeta de trabajo:
WORKDIR /src

# Copiar el proyecto completo:
COPY . .

# Configurar y compilar con CMake
RUN cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build --config Release

###################################################################

# Stage 2: Runtime

# Nos basamos en el S.O. Ubuntu
FROM ubuntu:22.04

# Establecer la carpeta de trabajo:
WORKDIR /app

# Solo copiamos el binario final:
COPY  --from=builder /src/build/practica2_multistage .

# Ejecutar el binario:
CMD ["./practica2_multistage"]
