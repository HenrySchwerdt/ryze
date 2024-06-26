package ui

import (
	"image/color"
	"ryze/internal/widgets"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/widget"
)

type RContainer struct {
	widget.BaseWidget
	nav     *widgets.Nav
	bar     *widgets.StatusBar
	content *fyne.CanvasObject
}

func NewRContainer() *RContainer {
	return &RContainer{
		bar: widgets.NewStatusBar().Background(color.RGBA{R: 50, G: 50, B: 50, A: 255}).Build(),
	}
}

func (r *RContainer) MinSize() fyne.Size {
	return fyne.NewSize(800, 800)
}

func (r *RContainer) CreateRenderer() fyne.WidgetRenderer {
	r.ExtendBaseWidget(r)
	return &rContainerRenderer{
		rContainer: r,
	}
}

var _ fyne.WidgetRenderer = (*rContainerRenderer)(nil)

type rContainerRenderer struct {
	rContainer *RContainer
}

func (r *rContainerRenderer) MinSize() fyne.Size {
	return r.rContainer.MinSize()
}

func (r *rContainerRenderer) Layout(size fyne.Size) {
	r.rContainer.bar.Resize(fyne.NewSize(size.Width, 24))
	r.rContainer.bar.Move(fyne.NewPos(0, size.Height-24))
}

func (r *rContainerRenderer) Objects() []fyne.CanvasObject {
	return []fyne.CanvasObject{r.rContainer.bar}
}

func (r *rContainerRenderer) Refresh() {
}

func (r *rContainerRenderer) Destroy() {
}
