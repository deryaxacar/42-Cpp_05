<div align="center">
  <h1>C++ Module 05</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>

</div>
<p align="center">
C++ dilinde nesne yönelimli programlama (OOP) yaklaşımını istisnalar (exceptions) ve farklı senaryolar üzerinden derinlemesine işlemektedir. Projede; bürokratik hiyerarşi ve formlar teması kullanılarak, sınıflar arasında kalıtım, soyut sınıflar (abstract class), çok biçimlilik (polymorphism), istisnaların kullanımı ve hata yakalama mekanizmaları gösterilmektedir.
</p>


### İçindekiler 📚
- [Ex00 - Bureaucrat](#ex00-bureaucrat)
- [Ex01 - Form](#ex01-form)
- [Ex02 - AForm ve Alt Sınıfları](#ex02-aform-ve-alt-siniflari)
- [Ex03 - Intern](#ex03-intern)

---

<a name="ex00-bureaucrat"></a>
### Ex00 - Bureaucrat

- Sabit bir `name` ve 1 ile 150 arasında olabilecek bir `grade` üyesi bulunur.
- `grade` aralığı geçersiz olduğunda istisna fırlatır (GradeTooHighException, GradeTooLowException).
- Derece yükseltme ve düşürme fonksiyonları da aynı şekilde geçersiz sınırda istisna yakalamayı öğretir.
- `operator<<` aşırı yüklenerek, bürokratın bilgilerini yazdırmayı sağlar.

---

<a name="ex01-form"></a>
### Ex01 - Form

- Form, ad (name), imzalanma durumu (signed), imza için gereken derece (grade to sign) ve uygulama için gereken derece (grade to execute) gibi sabit ve/veya özel alanlara sahiptir.
- Form’un imzalanması için gerekli grade sağlanmadığında istisna fırlatır (Form::GradeTooHighException, Form::GradeTooLowException).
- Bureaucrat tarafından `signForm()` fonksiyonuyla imzalanma aşaması ve ilgili mesajların yönetimi ele alınır.

---

<a name="ex02-aform-ve-alt-siniflari"></a>
### Ex02 - AForm ve Alt Sınıfları

- `Form` soyut sınıfa (AForm) dönüştürülür; artık nesne oluşturulamaz fakat kalıtım için temel görevi görür.
- `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` gibi somut sınıflar, AForm’dan türetilir ve kendi özel işlemlerini (`execute()`) uygular.
- Form’un imza ve yürütme (execute) koşulları kontrol edilerek, gerekiyorsa istisnalar (örneğin “Form is not signed” veya “Grade too low”) fırlatılır.

---

<a name="ex03-intern"></a>
### Ex03 - Intern

- `Intern` sınıfı, form oluşturma işini (makeForm) üstlenir.
- Parametre olarak aldığı form ismi ve hedef (target) bilgisini kullanarak doğru formu döndürür. Yanlış form ismi gelirse uyarı verir.
- Böylece, bürokratların sürekli form üretmesi yerine, `Intern` nesnesi bu görevi üstlenip bürokratik akışı kolaylaştırır.

---

Bu aşamalar boyunca, C++’ın istisna mekanizması (try/catch blokları), sınıf hiyerarşisi, kurucu/destructor kuralları, fonksiyon aşırı yükleme (overloading) ve çok biçimlilik gibi temel OOP prensipleri pratik örneklerle gösterilmektedir. Kodlama adımları sonunda ise öğrencilerin, sınıflar arası etkileşimi (özellikle hata yakalama ve kontrol mekanizmalarıyla) doğru şekilde yönetmeyi öğrenmeleri hedeflenir.

---

Bu README dosyası Derya ACAR tarafından hazırlanmıştır.