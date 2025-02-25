<div align="center">
  <h1>C++ Module 05</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>
</div>
<p align="center">
C++ dilinde nesne yönelimli programlama (OOP) yaklaşımını istisnalar (exceptions) ve farklı senaryolar üzerinden derinlemesine işlemektedir. Projede; bürokratik hiyerarşi ve formlar teması kullanılarak, sınıflar arasında kalıtım, soyut sınıflar (abstract class), çok biçimlilik (polymorphism), istisnaların kullanımı ve hata yakalama mekanizmaları gösterilmektedir.
</p>


### İçindekiler 📚

- [Ex00 - Bureaucrat](#ex00-bureaucrat)
  - [Try, Throw ve Exception Kullanımı](#try-throw-ve-exception-kullanımı)
- [Ex01 - Form](#ex01-form)
- [Ex02 - AForm ve Alt Sınıfları](#ex02-aform-ve-alt-siniflari)
- [Ex03 - Intern](#ex03-intern)
  - [Switch-case Kullanımı](#switch-case-kullanımı)

---

<a name="ex00-bureaucrat"></a>
<div align="center">
  <h2>Ex00 - Bureaucrat</h2>
</div>

- Sabit bir `name` ve 1 ile 150 arasında olabilecek bir `grade` üyesi bulunur.
- `grade` aralığı geçersiz olduğunda istisna fırlatır (GradeTooHighException, GradeTooLowException).
- Derece yükseltme ve düşürme fonksiyonları da aynı şekilde geçersiz sınırda istisna yakalamayı öğretir.
- `operator<<` aşırı yüklenerek, bürokratın bilgilerini yazdırmayı sağlar.

<a name="try-throw-ve-exception-kullanımı"></a>
<div align="center">
  <h3>Try, Throw ve Exception Kullanımı</h3>
</div>

C++’ta hatalı durumları yönetmek için `try`, `throw` ve `catch` blokları kullanılır:

- **try**
  - Hata oluşturma ihtimali olan kodlar burada yer alır.
- **throw**
  - Hatalı bir durum tespit edildiğinde, `throw` ile bir istisna fırlatılır.
- **catch**
  - `throw` ile fırlatılan istisna, uygun türdeki `catch` bloklarında yakalanır ve işlenir.

**Exception (İstisna) Nedir?**

C++’ta exception (istisna), program çalışırken beklenmeyen veya olağan dışı bir durumla karşılaşıldığında (örneğin geçersiz girdi, belli bir sınıra ulaşma, kaynak yetersizliği vb.) akışın kesilerek bu hatanın özel bir şekilde ele alınmasını sağlayan mekanizmadır. Bu sayede normal akış içinde hataların takibi yerine, hatalı durumlar ayrı bir blokta yönetilir ve kodun temizliği korunur.


```cpp
try {
    // Hata oluşturabilecek kod
    if (someCondition)
        throw std::runtime_error("Bir hata oluştu!");
    // ...
} catch (const std::runtime_error& e) {
    std::cerr << "Hata mesajı: " << e.what() << std::endl;
} catch (...) {
    std::cerr << "Bilinmeyen bir hata oluştu!" << std::endl;
}

```

Bu mekanizma sayesinde hatalar normal akıştan ayrı yönetilir ve kod daha temiz, anlaşılır hale gelir. Özellikle throw ve catch mekanizması kullanarak hataları türlerine göre (örneğin `GradeTooHighException`, `GradeTooLowException`) farklı şekillerde ele alabilirsiniz.


---

<a name="ex01-form"></a>
<div align="center">
  <h2>Ex01 - Form</h2>
</div>

- Form, ad (name), imzalanma durumu (signed), imza için gereken derece (grade to sign) ve uygulama için gereken derece (grade to execute) gibi sabit ve/veya özel alanlara sahiptir.
- Form’un imzalanması için gerekli grade sağlanmadığında istisna fırlatır (Form::GradeTooHighException, Form::GradeTooLowException).
- Bureaucrat tarafından `signForm()` fonksiyonuyla imzalanma aşaması ve ilgili mesajların yönetimi ele alınır.

---

<a name="ex02-aform-ve-alt-siniflari"></a>
<div align="center">
  <h2>Ex02 - AForm ve Alt Sınıfları</h2>
</div>

- `Form` soyut sınıfa (AForm) dönüştürülür; artık nesne oluşturulamaz fakat kalıtım için temel görevi görür.
- `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` gibi somut sınıflar, AForm’dan türetilir ve kendi özel işlemlerini (`execute()`) uygular.
- Form’un imza ve yürütme (execute) koşulları kontrol edilerek, gerekiyorsa istisnalar (örneğin “Form is not signed” veya “Grade too low”) fırlatılır.

---

<a name="ex03-intern"></a>
<div align="center">
  <h2>Ex03 - Intern</h2>
</div>

- `Intern` sınıfı, form oluşturma işini (makeForm) üstlenir.
- Parametre olarak aldığı form ismi ve hedef (target) bilgisini kullanarak doğru formu döndürür. Yanlış form ismi gelirse uyarı verir.
- Böylece, bürokratların sürekli form üretmesi yerine, `Intern` nesnesi bu görevi üstlenip bürokratik akışı kolaylaştırır.

---

<a name="switch-case-kullanımı"></a>
<div align="center"> 
  <h3>Switch-case Kullanımı</h3> 
</div>

**Switch-case Nedir?**

switch-case, bir değişkenin değerine göre belirlenmiş kod bloklarını seçerek çalıştırmayı sağlayan karar yapısıdır. Genellikle if-else if dizisini daha okunabilir hâle getirmek için tercih edilir. Yalnızca tam sayılar (int), karakterler (char) ve bazı derleyiciye özgü durumlarda da enum gibi türlerle kullanılabilir. Mantık olarak “değişkenin değeri neyse, ona karşılık gelen case bloğunu çalıştır” şeklinde özetlenebilir.
Aşağıdaki örnekte, switch yapısını kullanarak farklı grade (derece) değerleri için farklı işlem yapılmasını sağlıyoruz:

```cpp
#include <iostream>

int main() {
    int grade = 2; // Bu değer, kullanıcı girişi ya da başka bir fonksiyondan gelebilir
    
    switch (grade) {
        case 1:
            std::cout << "Grade = 1 (En yüksek derece)" << std::endl;
            // GradeTooHighException atılabilir
            break;
        case 150:
            std::cout << "Grade = 150 (En düşük derece)" << std::endl;
            // GradeTooLowException atılabilir
            break;
        default:
            std::cout << "Grade = " << grade << " (Geçerli aralıkta)" << std::endl;
            break;
    }

    return 0;
}

```
- `switch (grade`) ile değeri grade olan değişkene bakılır.
- `case 1` bloğu, gradein değeri `1` ise çalışır ve ardından break ile `switch` yapısından çıkılır.
- `case 150` bloğu, gradein değeri `150` ise çalışır ve ardından break ile `switch` yapısından çıkılır.
- `default` bloğu ise hiçbir `case` ile eşleşmeyen durumlarda devreye girer.

`switch-case`, bir değere göre dallanma yapmak istediğinizde `if-else-if` yapısını sadeleştirmeye yardımcı olur. Buradaki `default` bloğu, herhangi bir `case` ile eşleşmeyen durumlar için kullanılır.


---

Bu aşamalar boyunca, C++’ın istisna mekanizması (try/catch ve switch/case blokları), sınıf hiyerarşisi, kurucu/destructor kuralları, fonksiyon aşırı yükleme (overloading) ve çok biçimlilik gibi temel OOP prensipleri pratik örneklerle gösterilmektedir. Kodlama adımları sonunda ise öğrencilerin, sınıflar arası etkileşimi (özellikle hata yakalama ve kontrol mekanizmalarıyla) doğru şekilde yönetmeyi öğrenmeleri hedeflenir.

---

<p align="center">2025 This project was created by Derya ACAR.</p>

