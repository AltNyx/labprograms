import requests
import os
import bs4

# base url
url = 'https://xkcd.com'  

# create xkcd directory
os.makedirs('xkcd', exist_ok=True)

while not url.endswith('#'):
    # Download the page.
    print('Downloading page %s...' % url)
    res = requests.get(url)
    res.raise_for_status()

    soup = bs4.BeautifulSoup(res.text, 'html.parser')

    # Find the URL of the comic image.
    comic_elem = soup.select('#comic > img')
    if comic_elem == []:
        print('Could not find comic image.')
    else:
        comicUrl = 'https:' + comic_elem[0].get('src')
        # Download the image.
        print('Downloading image %s...' % (comicUrl))
        res = requests.get(comicUrl)
        res.raise_for_status()
    
        # Save the image to ./xkcd.
        with open(os.path.join('xkcd', os.path.basename(comicUrl)), 'wb') as image_file:
            for chunk in res.iter_content(100000):
                image_file.write(chunk)

    # Get the Prev button's url.
    prev_link = soup.select('a[rel="prev"]')[0]
    url = 'https://xkcd.com' + prev_link.get('href')

print('Done.')