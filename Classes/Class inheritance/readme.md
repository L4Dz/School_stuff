# Herança de Classes em C++

## Índice
- [O que é Herança](#o-que-é-herança)
- [Sintaxe Básica](#sintaxe-básica)
- [Tipos de Herança](#tipos-de-herança)
- [Construtores e Destrutores](#construtores-e-destrutores)
- [Métodos Virtuais e Polimorfismo](#métodos-virtuais-e-polimorfismo)
- [Classes Abstratas](#classes-abstratas)
- [Boas Práticas](#boas-práticas)
- [Detalhes Importantes](#detalhes-importantes)
- [Exemplos Práticos](#exemplos-práticos)
- [Erros Comuns](#erros-comuns)

---

## O que é Herança

A herança é um dos pilares da programação orientada a objetos que permite criar uma nova classe baseada numa classe existente. A classe derivada (filha) herda atributos e métodos da classe base (pai), podendo adicionar novos ou modificar os existentes.

**Terminologia:**
- **Classe Base/Pai/Superclasse**: A classe original
- **Classe Derivada/Filha/Subclasse**: A classe que herda da base
- **Herança**: "É-um" (is-a relationship)

---

## Sintaxe Básica

```cpp
class ClasseBase {
    // membros da classe base
};

class ClasseDerivada : public ClasseBase {
    // membros adicionais da classe derivada
};
```

### Exemplo Simples

```cpp
#include <iostream>
#include <string>

// Classe Base
class Animal {
protected:
    std::string nome_;
    int idade_;
    
public:
    Animal(const std::string& nome, int idade) 
        : nome_(nome), idade_(idade) {}
    
    virtual ~Animal() = default;
    
    const std::string& nome() const { return nome_; }
    int idade() const { return idade_; }
    
    virtual void som() const {
        std::cout << nome_ << " faz um som genérico\n";
    }
};

// Classe Derivada
class Cao : public Animal {
private:
    std::string raca_;
    
public:
    Cao(const std::string& nome, int idade, const std::string& raca)
        : Animal(nome, idade), raca_(raca) {}
    
    const std::string& raca() const { return raca_; }
    
    void som() const override {
        std::cout << nome_ << " faz: Au au!\n";
    }
    
    void abanarRabo() const {
        std::cout << nome_ << " está a abanar o rabo!\n";
    }
};
```

---

## Tipos de Herança

### 1. Herança Pública (`public`)
```cpp
class Derivada : public Base {
    // Membros public da Base permanecem public
    // Membros protected da Base permanecem protected
    // Membros private da Base não são acessíveis
};
```

### 2. Herança Protegida (`protected`)
```cpp
class Derivada : protected Base {
    // Membros public da Base tornam-se protected
    // Membros protected da Base permanecem protected
    // Membros private da Base não são acessíveis
};
```

### 3. Herança Privada (`private`)
```cpp
class Derivada : private Base {
    // Membros public da Base tornam-se private
    // Membros protected da Base tornam-se private
    // Membros private da Base não são acessíveis
};
```

**Nota:** Na maioria dos casos, usa-se herança pública (`public`).

---

## Construtores e Destrutores

### Construtores
```cpp
class Base {
public:
    Base(int valor) : valor_(valor) {
        std::cout << "Construtor da Base\n";
    }
private:
    int valor_;
};

class Derivada : public Base {
public:
    // OBRIGATÓRIO: chamar construtor da classe base
    Derivada(int valor, const std::string& nome) 
        : Base(valor), nome_(nome) {  // Chama Base(valor) primeiro
        std::cout << "Construtor da Derivada\n";
    }
private:
    std::string nome_;
};
```

### Destrutores
```cpp
class Base {
public:
    // SEMPRE virtual para herança!
    virtual ~Base() {
        std::cout << "Destrutor da Base\n";
    }
};

class Derivada : public Base {
public:
    ~Derivada() {
        std::cout << "Destrutor da Derivada\n";
    }
    // Destrutor da Base é chamado automaticamente depois
};
```

---

## Métodos Virtuais e Polimorfismo

### Métodos Virtuais
```cpp
class Base {
public:
    // Método virtual - pode ser sobrescrito
    virtual void metodo() const {
        std::cout << "Método da Base\n";
    }
    
    // Método não-virtual - não pode ser sobrescrito efetivamente
    void metodoNormal() const {
        std::cout << "Método normal da Base\n";
    }
};

class Derivada : public Base {
public:
    // Sobrescreve o método virtual
    void metodo() const override {
        std::cout << "Método da Derivada\n";
    }
    
    // "Esconde" o método da base (não é polimorfismo real)
    void metodoNormal() const {
        std::cout << "Método normal da Derivada\n";
    }
};
```

### Polimorfismo
```cpp
void exemploPolimorfismo() {
    Base* ptr = new Derivada();
    
    ptr->metodo();        // Chama Derivada::metodo() - polimorfismo
    ptr->metodoNormal();  // Chama Base::metodoNormal() - não é virtual
    
    delete ptr;
}
```

---

## Classes Abstratas

### Métodos Puramente Virtuais
```cpp
class Forma {  // Classe abstrata
public:
    virtual ~Forma() = default;
    
    // Método puramente virtual - DEVE ser implementado nas classes derivadas
    virtual double area() const = 0;
    virtual void desenhar() const = 0;
    
    // Método virtual normal - pode ser sobrescrito
    virtual void mostrarInfo() const {
        std::cout << "Área: " << area() << std::endl;
    }
};

class Retangulo : public Forma {
private:
    double largura_, altura_;
    
public:
    Retangulo(double largura, double altura) 
        : largura_(largura), altura_(altura) {}
    
    // OBRIGATÓRIO: implementar métodos puramente virtuais
    double area() const override {
        return largura_ * altura_;
    }
    
    void desenhar() const override {
        std::cout << "Desenhando retângulo " << largura_ << "x" << altura_ << std::endl;
    }
};
```

---

## Boas Práticas

### 1. Destrutores Virtuais
```cpp
class Base {
public:
    virtual ~Base() = default;  // SEMPRE virtual em classes base
};
```

### 2. Usar `override`
```cpp
class Derivada : public Base {
public:
    void metodo() const override;  // Garante que está a sobrescrever
};
```

### 3. Construtores com Lista de Inicialização
```cpp
class Derivada : public Base {
public:
    Derivada(int a, int b) : Base(a), membro_(b) {}  // Eficiente
private:
    int membro_;
};
```

### 4. Usar `const` Corretamente
```cpp
class Base {
public:
    // Getters sempre const
    const std::string& nome() const { return nome_; }
    
    // Métodos que não modificam o objeto
    virtual void mostrar() const = 0;
    
private:
    std::string nome_;
};
```

---

## Detalhes Importantes

### 1. Modificadores de Acesso
```cpp
class Base {
public:
    int publico;        // Acessível de qualquer lugar
protected:
    int protegido;      // Acessível na classe e classes derivadas
private:
    int privado;        // Apenas acessível na própria classe
};

class Derivada : public Base {
public:
    void exemplo() {
        publico = 1;     // OK
        protegido = 2;   // OK
        // privado = 3;  // ERRO! Não acessível
    }
};
```

### 2. Ordem de Construção/Destrução
```cpp
// Construção: Base → Derivada
// Destruição: Derivada → Base

class A {
public:
    A() { std::cout << "Construtor A\n"; }
    virtual ~A() { std::cout << "Destrutor A\n"; }
};

class B : public A {
public:
    B() { std::cout << "Construtor B\n"; }  // A já foi construído
    ~B() { std::cout << "Destrutor B\n"; }  // A será destruído depois
};
```

### 3. Slicing Problem
```cpp
void problemaSlicing() {
    Derivada d;
    Base b = d;  // CUIDADO! Perde parte da classe derivada
    
    // Solução: usar referências ou ponteiros
    Base& ref = d;    // OK
    Base* ptr = &d;   // OK
}
```

---

## Exemplos Práticos

### Exemplo 1: Sistema de Funcionários
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Funcionario {
protected:
    std::string nome_;
    double salarioBase_;
    
public:
    Funcionario(const std::string& nome, double salario)
        : nome_(nome), salarioBase_(salario) {}
    
    virtual ~Funcionario() = default;
    
    const std::string& nome() const { return nome_; }
    double salarioBase() const { return salarioBase_; }
    
    virtual double salarioTotal() const = 0;
    virtual void mostrarInfo() const {
        std::cout << "Nome: " << nome_ << ", Salário: " << salarioTotal() << std::endl;
    }
};

class FuncionarioRegular : public Funcionario {
public:
    FuncionarioRegular(const std::string& nome, double salario)
        : Funcionario(nome, salario) {}
    
    double salarioTotal() const override {
        return salarioBase_;
    }
};

class Gerente : public Funcionario {
private:
    double bonus_;
    
public:
    Gerente(const std::string& nome, double salario, double bonus)
        : Funcionario(nome, salario), bonus_(bonus) {}
    
    double salarioTotal() const override {
        return salarioBase_ + bonus_;
    }
    
    void mostrarInfo() const override {
        Funcionario::mostrarInfo();  // Chama método da classe base
        std::cout << "Bónus: " << bonus_ << std::endl;
    }
};

// Uso
void exemploFuncionarios() {
    std::vector<std::unique_ptr<Funcionario>> funcionarios;
    
    funcionarios.push_back(std::make_unique<FuncionarioRegular>("João", 1000));
    funcionarios.push_back(std::make_unique<Gerente>("Maria", 2000, 500));
    
    for (const auto& f : funcionarios) {
        f->mostrarInfo();  // Polimorfismo
    }
}
```

### Exemplo 2: Sistema de Formas Geométricas
```cpp
#include <iostream>
#include <cmath>

class Forma {
public:
    virtual ~Forma() = default;
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void desenhar() const = 0;
    
    void mostrarEstatisticas() const {
        std::cout << "Área: " << area() << ", Perímetro: " << perimetro() << std::endl;
    }
};

class Circulo : public Forma {
private:
    double raio_;
    
public:
    Circulo(double raio) : raio_(raio) {}
    
    double area() const override {
        return M_PI * raio_ * raio_;
    }
    
    double perimetro() const override {
        return 2 * M_PI * raio_;
    }
    
    void desenhar() const override {
        std::cout << "Desenhando círculo com raio " << raio_ << std::endl;
    }
};

class Retangulo : public Forma {
private:
    double largura_, altura_;
    
public:
    Retangulo(double largura, double altura) 
        : largura_(largura), altura_(altura) {}
    
    double area() const override {
        return largura_ * altura_;
    }
    
    double perimetro() const override {
        return 2 * (largura_ + altura_);
    }
    
    void desenhar() const override {
        std::cout << "Desenhando retângulo " << largura_ << "x" << altura_ << std::endl;
    }
};
```

---

## Erros Comuns

### 1. Esquecer Destrutor Virtual
```cpp
// ERRADO
class Base {
public:
    ~Base() {}  // Não virtual!
};

// CORRETO
class Base {
public:
    virtual ~Base() = default;  // Virtual!
};
```

### 2. Não Chamar Construtor da Base
```cpp
// ERRADO
class Derivada : public Base {
public:
    Derivada(int x) : membro_(x) {}  // Base não foi inicializada!
private:
    int membro_;
};

// CORRETO
class Derivada : public Base {
public:
    Derivada(int x, int y) : Base(x), membro_(y) {}  // Base inicializada
private:
    int membro_;
};
```

### 3. Não Usar `override`
```cpp
class Base {
public:
    virtual void metodo() const {}
};

// ERRADO - erro silencioso
class Derivada : public Base {
public:
    void metodo() {}  // Esqueceu const - não sobrescreve!
};

// CORRETO
class Derivada : public Base {
public:
    void metodo() const override {}  // Compilador verifica
};
```

### 4. Acesso Incorreto a Membros
```cpp
class Base {
private:
    int privado_;
protected:
    int protegido_;
};

class Derivada : public Base {
public:
    void exemplo() {
        protegido_ = 1;  // OK
        // privado_ = 2;  // ERRO! Não acessível
    }
};
```

---

## Resumo das Regras de Ouro

1. **Sempre** usa destrutor virtual em classes base
2. **Sempre** chama o construtor da classe base
3. **Sempre** usa `override` ao sobrescrever métodos virtuais
4. **Sempre** usa `const` corretamente em métodos
5. **Sempre** usa herança pública para relações "é-um"
6. **Sempre** torna métodos puramente virtuais (`= 0`) se a classe deve ser abstrata
7. **Sempre** usa `protected` para membros que classes derivadas devem aceder
8. **Sempre** usa referências ou ponteiros para polimorfismo
9. **Sempre** considera o princípio da responsabilidade única
10. **Sempre** documenta o comportamento esperado das classes derivadas

---

## Conclusão

A herança é uma ferramenta poderosa que permite criar hierarquias de classes bem estruturadas. Quando usada corretamente, promove reutilização de código e facilita a manutenção. No entanto, é importante entender bem os conceitos de polimorfismo, métodos virtuais e as regras de acesso para evitar problemas comuns.

Lembra-te: herança representa uma relação "é-um". Se não conseguires dizer "X é um Y", então provavelmente não devias usar herança!