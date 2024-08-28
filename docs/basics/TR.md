# Kipl Teknik Döküman

**Değişkenler**

- Değişkenler **var** anahtar sözcüğü ile tanımlanır.
- Değişken tanımlanırken tip belirtmek zorunludur.
- Değişken ismi maksimumu 64 karakter uzunluğunda olabilir.
- Değişken ismi harf, sayı veya alt tire (\_) karakterlerini içerebilir. Fakat değişken ismi sayı ile başlayamaz.
- Aynı scope içerisinde aynı isimlerle değişkenler tanımlanamaz.
- Değişkene değer atama işlemi, değişken tanımlandığı anda veya tanımlandıktan daha sonra gerçekleştirilebilir.
- Bir değişken aşağıdaki formatta tanımlanır.

```kipl
var <var_name> : <var_type>;
```

- Eğer değer atanarak tanımlanmak istenirse:

```kipl
var <var_name> : <var_type> = <value>;
```

Değişkenler tanımlandığında varsayılan olarak değer atamaları gerçekleştirilir.

Bu durumda tanımlanmış ama manuel olarak değer atanmamış bir değişkeni çağrıldığında hata oluşmaz varsayılan değer döndürülür.

**Varsayılan değerler**

i8, i16, i32, i64, i128, u8, u16, u32, u64, u128 **\=>** 0

f32, f64 **\=>** 0.0

bool **\=>** false

string **\=>** "" (boş string)

**Sabitler (Constants)**

- Atanan değerin çalışma zamanı içerisinde değiştirilemediği değişkenlere sabit değişkenler denir.
- Kipl programlama dilinde sabitler, **var** anahtar kelimesinin yerine **const** anahtar kelimesi yazılarak normal bir değişken oluşturur gibi oluşturulur.
- Sabitler tanımlandıklarında ilk değer atanana kadar **mutable** özellik gösterir. Değer ataması gerçekleştiğinde ise **unmutable** hale gelir ve bir daha değeri değiştirilemez.
- Scope kavramı değişkenlerde olduğu gibi aynen geçerlidir.
- Bir constant aşağıdaki formatta tanımlanır.

```kipl
const <var_name> : <var_type> = <value>;
```

**Kod Blokları (Scopes)**

- Kipl programlama dilinde bir scope süslü parantez karakterleri “{, }” ile oluşturulur.
- Scope “{“ ile açılır ve “}” ile kapanır.
- Açılan her scope’ un bir kapanışı olması gerekmektedir. Aksi takdirde programda _Curly brackets are not balanced_ açıklamasıyla _Syntax Error_ meydana gelecektir.
- Bir alt scope içerisinde tanımlanan değişkenlere üst scope’lardan erişilemez Fakat üst scopelar’da tanımlanan değişkenlere alt scope’lardan erişilebilir.
- Bir scope içerisinde aynı isimle birden fazla değişken tanımlanamaz fakat farklı scope’larda aynı isimle değişkenler tanımlanabilir.
- Alt scope’da bir değişken çağrıldığında öncelikle bulunduğu scope içerisinde arama yapar eğer yoksa üst scope’ları gezilir Bu durumda alt ve üst scope’da aynı isimle iki farklı değişken tanımlandığında alt scope’daki değişken geçerli olur.

**For Döngüsü**

- Döngüler **for** anahtar kelimesi ile oluşturulur.
- Bir for döngüsü aşağıdaki formatta oluşturulur. **(bool_value: true | false)**

```kipl
for <bool_value> {
    // codes
}
```

**Dosya Dahil Etme**
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