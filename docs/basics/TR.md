# Kipl Teknik Döküman

## Değişkenler

- Değişkenler **var** anahtar sözcüğü ile tanımlanır.
- Değişken tanımlanırken tip belirtmek zorunludur.
- Değişken ismi maksimumu 64 karakter uzunluğunda olabilir.
- Değişken ismi harf, sayı veya alt tire (\_) karakterlerini içerebilir. Fakat değişken ismi sayı ile başlayamaz.
- Aynı scope içerisinde aynı isimlerle değişkenler tanımlanamaz.
- Değişkene değer atama işlemi, değişken tanımlandığı anda veya tanımlandıktan daha sonra gerçekleştirilebilir.
- Bir değişken aşağıdaki formatta tanımlanır.

```kipl
var <var_name> : <var_type>
```

- Eğer değer atanarak tanımlanmak istenirse:

```kipl
var <var_name> : <var_type> = <value>
```

Değişkenler tanımlandığında varsayılan olarak değer atamaları gerçekleştirilir.

Bu durumda tanımlanmış ama manuel olarak değer atanmamış bir değişkeni çağrıldığında hata oluşmaz varsayılan değer döndürülür.

## Varsayılan değerler

i8, i16, i32, i64, i128, u8, u16, u32, u64, u128 **\=>** 0

f32, f64 **\=>** 0.0

bool **\=>** false

string **\=>** "" (boş string)

## Sabitler (Constants)

- Atanan değerin çalışma zamanı içerisinde değiştirilemediği değişkenlere sabit değişkenler denir.
- Kipl programlama dilinde sabitler, **var** anahtar kelimesinin yerine **const** anahtar kelimesi yazılarak normal bir değişken oluşturur gibi oluşturulur.
- Sabitler tanımlandıklarında ilk değer atanana kadar **mutable** özellik gösterir. Değer ataması gerçekleştiğinde ise **unmutable** hale gelir ve bir daha değeri değiştirilemez.
- Scope kavramı değişkenlerde olduğu gibi aynen geçerlidir.
- Bir constant aşağıdaki formatta tanımlanır.

```kipl
const <var_name> : <var_type> = <value>"
```

## Kod Blokları (Scopes)
- Kipl programlama dilinde bir scope süslü parantez karakterleri “{, }” ile oluşturulur.
- Scope "{" ile açılır ve "}" ile kapanır.
- Açılan her scope’ un bir kapanışı olması gerekmektedir. Aksi takdirde programda _Curly brackets are not balanced_ açıklamasıyla _Syntax Error_ meydana gelecektir.
- Bir alt scope içerisinde tanımlanan değişkenlere üst scope’lardan erişilemez Fakat üst scopelar’da tanımlanan değişkenlere alt scope’lardan erişilebilir.
- Bir scope içerisinde aynı isimle birden fazla değişken tanımlanamaz fakat farklı scope’larda aynı isimle değişkenler tanımlanabilir.
- Alt scope’da bir değişken çağrıldığında öncelikle bulunduğu scope içerisinde arama yapar eğer yoksa üst scope’ları gezilir Bu durumda alt ve üst scope’da aynı isimle iki farklı değişken tanımlandığında alt scope’daki değişken geçerli olur.

## For Döngüsü
- Döngüler **for** anahtar kelimesi ile oluşturulur.
- Bir for döngüsü aşağıdaki formatta oluşturulur. **(bool_value: true | false)**

```kipl
for <bool_value> {
    // codes
}
```

## Koşullu İfadeler - If - Else - Else If
- Bir ifadenin doğruluğunun kontrolü için Kipl programlama dilinde if else yapısı statemant'ları kullanılır.
- Eğer ifade doğruysa if bloğuna girilir ve o bloktaki ifadeler çalışıtırlır. Fakat ifade yanlış ise else if ve else anahtar kelimeleri aranır. 
- Else if, if bloğu yanlış olduğunda kontrol edilir. Eğer else if'deki ifade yanlış ise varsa diğer else ifler kontrol edilir.
- Else ise if ve else if'deki ifadelerden doğru sonuç dönmemesi durumunda çalıştırılacak olan bloktur.
- Aşağıda örnek bir if yapısı bulunmaktadır.
```kipl
if 2 > 3 {
    out "this is the if block"
} else if 4 > 3 {
    out "this is the else if block"
} else {
    out "this is the else block"
}
```

## Dosya Dahil Etme
- Kipl programlama dilinde birden fazla dosya ile tek bir proje üzerinde çalışılabilir.
- Bir dosyadaki kodları diğer dosyaya dahil etmek için **import** anahtar kelimesi kullanılır.
- Dosya dahil edilirken dosyanın uzantısı yani ".kipl" yazılmaz. Interpreter sadece dosyanın adına göre arama yapar.
- .kipl uzantısına sahip olmayan bir dosya dahil edilemez.
- Dosyanın dahil edilip edilmeme kontrolü tamamen programcıya aittir. Daha önce dahil edilen bir dosya tekrar dahil edilebilir. Ve bu istenmeyen bir durumdur.
- Gelecekte dosya dahil etme kontrolleri interpreter'a devredilecektir.
- Bir dosya dahil etme işlemi aşağıdaki format ile gerçekleştirilir.
```kipl
import "<file_name>"
```

## Switch-Case Koşullu İfadesi
- Bir ifadenin değer kontrolü için if-else yapısı kullanılabileceği gibi daha efektif bir yöntem olan switch-case yapısı da tercih edilebilir.
- Switch case'de case'ler tek tek kontrol edilir. Case'in değeri ile kontrol edilen değer eşit olduğunda o casedeki kodlar çalıştırılır ve diğer case'ler incelenmez.
- Eğer hiçbir case'de eşitlik sağlanmazsa varsa default durumunun içerisindeki kodlar çalıştırılır. Eğer yoksa switch case içerisinde hiçbir işlem yapılmadan sonlandırılır.
- Switch case'de kotrol edilen değer ile case'lerdeki değerlerin tipleri aynı olmak zorundadır. (Numerik, metinsel, mantıksal). Aksi takdirde çalışma zamanı hatası meydana gelecektir.
- Kipl'de bir switch case aşağıdaki formatta oluşturulur.
```kipl
var number: i32 = 12:

switch number {
    case 11:
        out "Number is 11"
    case 12:
        out "Number is 12"
    case 13:
        out "Number is 13"
    default:
        out "Number is unkown"
}
```

## Out Komutu
- Out bir dil yapısıdır bir fonksiyon değildir.
- Konsol ekranına bir ifade bastırılmak istenildiğinde kullanılır.
- Ekrana bastırılmak istenilen ifade string beri tipinde olmak zorunda değildir. Her hangi bir veri türüne sahip ifade ekrana bastırılabilir.
- Out ifadesi aşağıdaki gibi kullanılır.
```kipl
out "Hello World"
out  5 + 9 // result 14
```
    
## Kaçış Karakterleri
- Bir stringin içerisinde alt satıra geçme, çift tırnak kullanma, back slash(\) kullanma, 1 tab boşluk bırakma gibi işlemler için kaçış karakterleri kullanılır.
- Alt satıra geçmek için "\n" kullanılır.
```kipl
out "Hello \nWorld!"
```
- 1 tab boşluk bırakmak için "\t" kullanılır.
```kipl
out "Hello \tWorld!"
```
- Çift tırnak kullanmak için \\" kullanılır.
```kipl
out "\"Hello World!\""
```
- Back Slash kullanmak için \\\ kullanılır.
```kipl
out "Hello \\ World!"
```

## Fonksiyonlar
- Kipl programlam dilinde bir fonksiyon **func** anahtar kelimesi ile oluşturulur.
- Func anahtar kelimesinin ardından ':' operatörü aracılığıyla fonksiyonun geriye dönüş tipi belirtilir.
- Eğer fonskiyon geriye bir değer döndürmeyecekse dönüş tipi **void** olarak belirtilir.
- Fonksiyonun geriye dönüş tipi geriye döndürülen değer ile örtüşmelidir.
- Bir fonskiyon teorik olarak sınırsız sayıda parametre alabilir.
- Fonksiyonda parametrelerin veri tipleri ayrı ayrı belirtilmelidir.
- Fonksiyon ismi maksimum 64 karakter uzunluğunda olabilir.
- Bir fonksiyon aşağıdaki formatta tanımlanır.
```kipl
func sum: i16 => num1: i8, num2: i8 {
    return num1 + num2
}
```
- Bir fonksiyon, fonksiyonun ismi, ardından açma kapama parantezleri kullanılarak çağırılır.
- Eğer fonksiyona parametre veya parametreler gönderilmesi gerekiyorsa parantezler içerisine gerekli parametreler  ',' ayıracı kullanılarak yerleştirilir.
- Aşağıda daha önce oluşturulmuş sum fonksiyonun çağırılma işlemi yer almaktadır.
```kipl
out sum(2, 8)
```