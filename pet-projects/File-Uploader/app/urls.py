from django.urls import path,include
from . import views
app_name = 'app'
urlpatterns = [
    path("success/", views.successfully_uploaded, name='successfully_uploaded'),
    path("upload/", views.upload_file, name= "upload_file"),
]