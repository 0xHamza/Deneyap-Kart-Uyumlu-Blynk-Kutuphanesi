# Deneyap-Kart-Uyumlu-Blynk-Kutuphanesi
Blynk for Deneyap Kart, This library has been modified to provide compatibility with the Blynk library for Deneyap board users.

# Deneyap Kartı için Blynk Kütüphanesi Uyumu

Bu kütüphane, Deneyap kartı kullanıcıları için Blynk kütüphanesi uyumluluğunu sağlamak amacıyla düzenlenmiştir. Blynk kütüphanesi ve Deneyap kartı birlikte kullanıldığında, T, T1, T2, T3 ve T4 gibi değişken isimleri iki kütüphane arasında çakışma sorunlarına neden olmaktadır. Bu sorunları çözmek için, Blynk kütüphanesi içindeki değişken isimleri Deneyap kartı kütüphanesi ile uyumlu hale getirilmiştir. Bu sayede, Deneyap kartı kullanıcıları Blynk kütüphanesini sorunsuz bir şekilde kullanabilirler.

Bu repoyu indirmeden sorunu kendi yüklü olan blynk kütüphanenizde çözmek isterseniz. Kütüphanenizin yüklü olduğu yerdeki bütün blynk dosyaları içerisindeki 'T, T1, T2, T3 ve T4' isimli değişkenlerin adını farklı bir isim yapmanız sorunu çözecektir örneğin 'T_Blynk, T3_Blynk, vb'. Veya aynı işlevi deneyap kart kütüpahnenizin içerisindeki dosyalardaki T değişkenlerine uygulayarak da çözebilirsiniz.

## Nasıl Kullanılır

1. Kütüphaneyi indirin.
2. İndirdiğiniz kütüphaneyi, Arduino IDE'ye yüklemek için aşağıdaki adımları uygulayın:

    - Arduino IDE'yi açın.
    - Sketch > Include Library > Add .ZIP Library seçeneğine tıklayın.
    - İndirdiğiniz kütüphanenin .zip dosyasını seçin.
    - Kütüphane yüklendikten sonra, Arduino IDE'yi yeniden başlatın.

3. Kütüphaneyi kullanmak için, Arduino IDE'deki örnek kodlardan birini açın. Örnek kodların çoğu, BlynkSimpleEsp32 kütüphanesini kullanır. Bu örnek kodları, Deneyap kartı ile uyumlu olarak çalışacak şekilde değiştirmeniz gerekebilir. Bu yüzden 'BlynkSimpleEsp32.h' dosyasını kullanan örnekleri çalıştırmanız sorun çıkmaması adına önemli.
4. Deneyap Kart Projelerinizde Blynk orjinal kütüphanesi yerine bu kütüphaneyi kullanın.

## Sorun Giderme

Eğer Blynk kütüphanesi ve Deneyap kartı uyumlu hale getirildiği halde hala sorun yaşıyorsanız, lütfen aşağıdaki adımları takip edin:

1. Arduino IDE'yi kapatın.
2. Arduino IDE'ye yüklediğiniz kütüphaneyi, Arduino IDE'nin yüklü olduğu klasöre giderek silin.
3. Arduino IDE'yi yeniden açın ve kütüphaneyi tekrar yükleyin.
4. Kodunuzu yeniden derleyin ve yükleyin.

Bu işlem sorunu çözmezse, lütfen iletişim bilgilerimizden bize ulaşın.

## Lisans

Bu proje, orijinal Blynk kütüphanesi üzerinden geliştirilmiştir. Orijinal Blynk kütüphanesi, MIT lisansı ile lisanslanmıştır. Bu nedenle, bu projenin de MIT lisansı altında paylaşıldığını belirtmek isteriz. Daha fazla bilgi için, lütfen [orijinal Blynk kütüphanesi sayfasını](https://github.com/blynkkk/blynk-library) ziyaret edin.

## Katkıda Bulunma

Bu kütüphaneye katkıda bulunmak isterseniz, lütfen bir pull request gönderin veya bir konu açın. Katkılarınızdan memnuniyet duyarız!

## Sorun Bildirme

Bu kütüphanede herhangi bir sorunla karşılaşırsanız, lütfen bir konu açın veya bir e-posta gönderin. Sorunları çözmek için elimizden geleni yapacağız.

## Teşekkürler

Bu kütüphaneyi kullanarak projelerinizi geliştirmenize yardımcı olabildiysek ne mutlu bize! 

## İletişim

E-posta: 0xhamza

Bu README.md dosyası, MIT lisansı ile lisanslanmıştır. Daha fazla bilgi için, LICENSE dosyasına bakın.
