const pageContainerEl = document.querySelector('.page');
const textareaEl = document.querySelector('.page > .textarea');
const overlayEl = document.querySelector('.page > .overlay');

const isMobile = /iPhone|iPad|iPod|Android/i.test(navigator.userAgent);

function applyPaperStyles() {
  pageContainerEl.style.border = 'none';
  pageContainerEl.style.background = 'linear-gradient(to right,#eee, #ddd)';
  overlayEl.style.background = `linear-gradient(${
    Math.random() * 360
  }deg, #0008, #0000)`;
  overlayEl.style.display = 'block';
  textareaEl.classList.add('paper');
}

function removePaperStyles() {
  pageContainerEl.style.border = '1px solid #ccc';
  pageContainerEl.style.background = 'linear-gradient(to right,#fff, #fff)';
  overlayEl.style.display = 'none';
  textareaEl.classList.remove('paper');
}

function addFontFromFile(fileObj) {
  const reader = new FileReader();
  reader.onload = (e) => {
    const newFont = new FontFace('temp-font', e.target.result);
    newFont.load().then((loadedFace) => {
      document.fonts.add(loadedFace);
      textareaEl.style.fontFamily = 'temp-font';
    });
  };
  reader.readAsArrayBuffer(fileObj);
}

/**
 * @method createPDF
 * @param imgs array of images (in base64)
 * @description
 * Creates PDF from list of given images
 */
function createPDF(imgs) {

  const doc = new jsPDF('p', 'pt', 'a4');
  const width = doc.internal.pageSize.width;
  const height = doc.internal.pageSize.height;
  for (let i in imgs) {
    doc.text(10, 20, '');
    doc.addImage(imgs[i], 'JPEG', 25, 50, width - 50, (height - 80), "image-"+i);
    if (i != imgs.length - 1) {
      doc.addPage();
    }
  }
  doc.save();
}


/**
 *
 * @param {string} hashval - id of a tag to scroll to (e.g #container)
 */

const smoothlyScrollTo = (hashval) => {
  let target = document.querySelector(hashval);
  target.scrollIntoView({
    behavior: 'smooth',
    block: 'start',
  });
  history.pushState(null, null, hashval);
};


export {
  isMobile,
  applyPaperStyles,
  removePaperStyles,
  addFontFromFile,
  createPDF,
  smoothlyScrollTo,
};
