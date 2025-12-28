# Update currency from USD to INR
$htmlPath = "c:\Users\ASHISH\Desktop\Ashith\Shaza\frontend\index.html"
$content = Get-Content $htmlPath -Raw -Encoding UTF8
$content = $content.Replace('$','₹')
$content | Out-File $htmlPath -Encoding UTF8 -NoNewline
Write-Host "Currency updated to INR successfully!"
