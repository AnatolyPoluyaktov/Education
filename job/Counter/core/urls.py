from django.urls import path
from .views import CountView


urlpatterns = [
    path('', CountView.as_view()),
]