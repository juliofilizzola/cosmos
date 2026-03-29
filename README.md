# Cosmos

Cosmos é um projeto C++ que simula um sistema de partículas, foguetes e estrelas, provavelmente com fins educacionais ou de demonstração gráfica.

## Estrutura do Projeto

- `src/` — Código-fonte principal do projeto:
  - `Game.cpp` / `Game.hpp`: Lógica principal do jogo/simulação.
  - `ParticleSystem.cpp` / `ParticleSystem.hpp`: Implementação do sistema de partículas.
  - `Rocket.cpp` / `Rocket.hpp`: Implementação dos foguetes.
  - `Star.cpp` / `Star.hpp`: Implementação das estrelas.
  - `main.cpp`: Ponto de entrada da aplicação.
- `CMakeLists.txt` — Script de build para o CMake.
- `cmake-build-debug/` — Diretório de build gerado pelo CMake (pode ser ignorado para versionamento).

## Como compilar

1. Certifique-se de ter o [CMake](https://cmake.org/) e um compilador C++ instalado (ex: g++, clang++).
2. No terminal, execute:

```sh
cd /Volumes/DEV/development/cosmos
cmake -B cmake-build-debug
cmake --build cmake-build-debug
```

3. O executável será gerado em `cmake-build-debug/cosmos`.

## Como executar

Após a compilação, execute:

```sh
./cmake-build-debug/cosmos
```

## Observações

- O projeto pode depender de bibliotecas gráficas (ex: SFML, SDL). Verifique o `CMakeLists.txt` para dependências adicionais.
- Para desenvolvimento, utilize um ambiente compatível com C++ (ex: CLion, VSCode, QtCreator).

## Licença

Defina a licença do projeto conforme necessário.

