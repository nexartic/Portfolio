<?php
$metrika = "
<script type='text/javascript' >
    (function (d, w, c) {
        (w[c] = w[c] || []).push(function() {
            try {
                w.yaCounter51002306 = new Ya.Metrika2({
                    id:51002306,
                    clickmap:true,
                    trackLinks:true,
                    accurateTrackBounce:true,
                    webvisor:true
                });
            } catch(e) { }
        });

        var n = d.getElementsByTagName('script')[0],
            s = d.createElement('script'),
            f = function () { n.parentNode.insertBefore(s, n); };
        s.type = 'text/javascript';
        s.async = true;
        s.src = 'https://mc.yandex.ru/metrika/tag.js';

        if (w.opera == '[object Opera]') {
            d.addEventListener('DOMContentLoaded', f, false);
        } else { f(); }
    })(document, window, 'yandex_metrika_callbacks2');
</script>
<noscript><div><img src='https://mc.yandex.ru/watch/51002306' style='position:absolute; left:-9999px;' alt='' /></div></noscript>";

$header = "<html lang='en'>".
"<head>".
    $metrika.
	"<meta charset='UTF-8'>".
	"<title>".$title."</title>".
	"<meta name='yandex-verification' content='7ca198455e5211ce' />".
	"<meta name='viewport' content='width=device-width, initial-scale=1.0'>".
	"<meta name='description' content='".$discription."' />".
	"<meta name='keywords' content='".$keywords."'>".
	"<link rel='icon' href='/favico.ico' type='image/x-icon'>";
echo $header;
?>