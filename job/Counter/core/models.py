from django.conf import settings
from django.db import models
from django.conf import settings


class Counter(models.Model):
    count = models.PositiveIntegerField(default=0)
    user = models.ForeignKey(settings.AUTH_USER_MODEL,
                             on_delete=models.CASCADE)

    class Meta:
        verbose_name = 'counter'
        verbose_name_plural = 'counters'
