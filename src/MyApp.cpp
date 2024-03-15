#include "MyApp.h"

#define WINDOW_WIDTH 940
#define WINDOW_HEIGHT 540

MyApp::MyApp()
{
  ///
  /// Create our main App instance.
  ///
  app_ = App::Create();

  ///
  /// Create a resizable window by passing by OR'ing our window flags with
  /// kWindowFlags_Resizable.
  ///
  window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT,
                           false, kWindowFlags_Borderless);

  ///
  /// Create our HTML overlay-- we don't care about its initial size and
  /// position because it'll be calculated when we call OnResize() below.
  ///
  overlay_ = Overlay::Create(window_, 1, 1, 0, 0);

  ///
  /// Force a call to OnResize to perform size/layout of our overlay.
  ///
  OnResize(window_.get(), window_->width(), window_->height());

  ///
  /// Load a page into our overlay's View
  ///
  overlay_->view()->LoadURL("file:///loginForm.html");

  ///
  /// Register our MyApp instance as an AppListener so we can handle the
  /// App's OnUpdate event below.
  ///
  app_->set_listener(this);

  ///
  /// Register our MyApp instance as a WindowListener so we can handle the
  /// Window's OnResize event below.
  ///
  window_->set_listener(this);

  ///
  /// Register our MyApp instance as a LoadListener so we can handle the
  /// View's OnFinishLoading and OnDOMReady events below.
  ///
  overlay_->view()->set_load_listener(this);

  ///
  /// Register our MyApp instance as a ViewListener so we can handle the
  /// View's OnChangeCursor and OnChangeTitle events below.
  ///
  overlay_->view()->set_view_listener(this);
}

void MyApp::closeWindowFromHTML()
{
  // Schließe das Fenster
  app_->Quit();
}

MyApp::~MyApp()
{
}

void MyApp::Run()
{
  app_->Run();
}

void MyApp::OnUpdate()
{
  ///
  /// This is called repeatedly from the application's update loop.
  ///
  /// You should update any app logic here.
  ///
    // window_->MoveTo(mousePos.x, mousePos.y);
}

void MyApp::OnResize(ultralight::Window *window, uint32_t width, uint32_t height)
{
  ///
  /// This is called whenever the window changes size (values in pixels).
  ///
  /// We resize our overlay here to take up the entire window.
  ///
  overlay_->Resize(width, height);
}

void MyApp::OnClose(ultralight::Window *window)
{
  app_->Quit();
}

void MyApp::OnFinishLoading(ultralight::View *caller,
                            uint64_t frame_id,
                            bool is_main_frame,
                            const String &url)
{
  ///
  /// This is called when a frame finishes loading on the page.
  ///
}

void MyApp::OnChangeCursor(ultralight::View *caller,
                           Cursor cursor)
{
  ///
  /// This is called whenever the page requests to change the cursor.
  ///
  /// We update the main window's cursor here.
  ///
  window_->SetCursor(cursor);
}

void MyApp::OnChangeTitle(ultralight::View *caller,
                          const String &title)
{
  ///
  /// This is called whenever the page requests to change the title.
  ///
  /// We update the main window's title here.
  ///
  window_->SetTitle(title.utf8().data());
}


// This callback will be bound to 'OnButtonClick()' on the page.
JSValueRef MyApp::OnCloseClick(JSContextRef ctx, JSObjectRef function,
                               JSObjectRef thisObject, size_t argumentCount,
                               const JSValueRef arguments[], JSValueRef *exception)
{
  exit(EXIT_SUCCESS);
  return JSValueMakeNull(ctx);
}

// // This callback will be bound to 'OnButtonClick()' on the page.
// JSValueRef OnExample(JSContextRef ctx, JSObjectRef function,
//   JSObjectRef thisObject, size_t argumentCount,
//   const JSValueRef arguments[], JSValueRef* exception) {

//     app_->Quit();
//   const char* str =
//     "document.getElementById('result').innerText = 'Ultralight rocks!'";

//   // Create our string of JavaScript
//   JSStringRef script = JSStringCreateWithUTF8CString(str);

//   // Execute it with JSEvaluateScript, ignoring other parameters for now
//   JSEvaluateScript(ctx, script, 0, 0, 0, 0);

//   // Release our string (we only Release what we Create)
//   JSStringRelease(script);

//   return JSValueMakeNull(ctx);
// }

// Use LoadListener::OnDOMReady to wait for the DOM to load.
void MyApp::OnDOMReady(View *caller,
                       uint64_t frame_id,
                       bool is_main_frame,
                       const String &url)
{

  // Acquire the JS execution context for the current page.
  auto scoped_context = caller->LockJSContext();

  // Typecast to the underlying JSContextRef.
  JSContextRef ctx = (*scoped_context);

  // Create a JavaScript String containing the name of our callback.
  JSStringRef name = JSStringCreateWithUTF8CString("OnCloseClick");
  JSObjectRef func = JSObjectMakeFunctionWithCallback(ctx, name,
                                                      OnCloseClick);
  // Get the global JavaScript object (aka 'window')
  JSObjectRef globalObj = JSContextGetGlobalObject(ctx);
  JSObjectSetProperty(ctx, globalObj, name, func, 0, 0);

  // Release the JavaScript String we created earlier.
  JSStringRelease(name);
}