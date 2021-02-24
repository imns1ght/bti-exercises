# Threads

## Introdução

O software resolve integrais definidas através do método da regra do trapézio utilizando o `pthread` da linguagem C.

As funções disponíveis são:

- `f1(𝑥) = 5,0, 𝑎 = 0,0, 𝑏 = 10,0`
- `f2(𝑥) = sen 2,0 ∗ 𝑥 + cos (5,0 ∗ 𝑥), 𝑎 = 0,0, 𝑏 = 2,0`

## Alunos

- Jefferson Bruno Silva - [Github](https://github.com/imns1ght)
- Odin :p

## Compilando e Executando

Assumindo que você tem o GCC 10 instalado, utiliza uma distribuição Linux e está dentro do diretório do projeto, podemos executar os
seguintes comandos para executar a aplicação:

### Compilando

```bash
  gcc threads.c -o threads -pthread -lm
```

### Executando

Podemos executar o programa passando como argumentos:

```bash
./threads f<k> <t> <n>
```

- k: `1` ou `2` - número de identificação da função desejada
- t: `t > 1` e `t <= 10` - número de threads utilizadas para o cálculo
- n: `n indefinido` - número de trapézios utilizados para o cálculo

### Testando

- Testar f1(x) com `t = 6, n = 120` e `t = 7, n = 200` - resultado esperado: `50e`
- Testar f2(x) com `t = 6, n = 120` e `t = 7, n = 200` - resultado esperado: `~e-15` no primeiro caso e `~e-16` no segundo caso
