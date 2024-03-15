const cursorSmall = document.querySelector('.small');

function positionElement(e) {
	const mouseY = e.clientY;
	const mouseX = e.clientX;

	cursorSmall.style.transform = `translate3d(calc(${mouseX}px - 5px), calc(${mouseY}px - 6px), 0)`;
}

window.addEventListener('mousemove', positionElement);